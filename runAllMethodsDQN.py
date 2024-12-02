import os
import json
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, auc, precision_recall_curve
from stable_baselines3 import DQN

# Not good script, disregard
# Load data from directories
def load_data_from_directory(directory):
    data = []
    for root, _, files in os.walk(directory):
        for file in files:
            if file.endswith(".json"):
                with open(os.path.join(root, file), 'r') as f:
                    entry = json.load(f)
                    data.append((entry["tokens"], entry["label"]))
    return data

# Helper function to load data for a given tokenization method
def load_data_for_method(method):
    train_data = load_data_from_directory(f"vuln_train_{method}") + load_data_from_directory(f"patched_train_{method}")
    test_data = load_data_from_directory(f"vuln_test_{method}") + load_data_from_directory(f"patched_test_{method}")
    
    X_test = [entry[0] for entry in test_data]
    y_test = [entry[1] for entry in test_data]
    
    return X_test, y_test

# Build vocabulary from training data
def build_vocab(X_train_full):
    vocab = {"<PAD>": 0, "<UNK>": 1}
    current_id = 2
    for sequence in X_train_full:
        for token in (token for sublist in sequence for token in sublist) if isinstance(sequence[0], list) else sequence:
            if token not in vocab:
                vocab[token] = current_id
                current_id += 1
    return vocab

# Encode sequences using vocabulary
def encode_sequences(sequences, vocab, max_length):
    unk_id = vocab["<UNK>"]
    encoded = []
    for sequence in sequences:
        encoded_sequence = [vocab.get(token, unk_id) for token in sequence]
        if len(encoded_sequence) > max_length:
            encoded_sequence = encoded_sequence[:max_length]
        else:
            encoded_sequence += [vocab["<PAD>"]] * (max_length - len(encoded_sequence))
        encoded.append(encoded_sequence)
    return np.array(encoded)

# Pre-trained model file
model_file = "trained_dqn_model_58.54.zip"
model = DQN.load(model_file)

# Set tokenization methods
tokenization_methods = ["basic", "ast", "normalize", "syntax", "cfg"]
max_length = 100  # Set max length for sequences

# Evaluate and save metrics for all methods
for method in tokenization_methods:
    print(f"Processing method: {method}")
    
    # Load and preprocess data
    X_test, y_test = load_data_for_method(method)
    vocab = build_vocab(X_test)
    X_test_encoded = encode_sequences(X_test, vocab, max_length)
    
    # Predict probabilities
    y_pred_prob = model.predict(X_test_encoded, deterministic=True)[0]
    
    # Compute metrics
    fpr, tpr, _ = roc_curve(y_test, y_pred_prob)
    roc_auc = auc(fpr, tpr)
    precision, recall, _ = precision_recall_curve(y_test, y_pred_prob)
    prc_auc = auc(recall, precision)
    
    # Save ROC Curve to file
    roc_curve_file = f"roc_curve_{method}.png"
    plt.figure(figsize=(10, 6))
    plt.plot(fpr, tpr, color='blue', lw=2, label=f'ROC curve (area = {roc_auc:.2f})')
    plt.plot([0, 1], [0, 1], color='gray', lw=2, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title(f'Receiver Operating Characteristic (ROC) Curve - {method}')
    plt.legend(loc="lower right")
    plt.savefig(roc_curve_file)
    plt.close()
    
    # Save Precision-Recall Curve to file
    prc_curve_file = f"prc_curve_{method}.png"
    plt.figure(figsize=(10, 6))
    plt.plot(recall, precision, color='blue', lw=2, label=f'PRC curve (area = {prc_auc:.2f})')
    plt.xlabel('Recall')
    plt.ylabel('Precision')
    plt.title(f'Precision-Recall Curve - {method}')
    plt.legend(loc="lower left")
    plt.savefig(prc_curve_file)
    plt.close()
    
    # Save metrics report to file
    metrics_report_file = f"metrics_report_{method}.txt"
    with open(metrics_report_file, 'w') as f:
        f.write(f"Method: {method}\n")
        f.write(f"ROC AUC: {roc_auc:.2f}\n")
        f.write(f"PRC AUC: {prc_auc:.2f}\n")
        f.write(f"\nROC Curve saved to: {roc_curve_file}\n")
        f.write(f"Precision-Recall Curve saved to: {prc_curve_file}\n")
    
    print(f"Metrics report saved to {metrics_report_file}")
