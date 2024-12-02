import os
import json
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, roc_auc_score, precision_recall_curve, auc
from stable_baselines3 import DQN
from stable_baselines3.common.torch_layers import nn
from train import train_and_eval_dqn, create_env
from sklearn.model_selection import train_test_split

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
    
    X_train_full = [entry[0] for entry in train_data]
    y_train_full = [entry[1] for entry in train_data]
    X_test = [entry[0] for entry in test_data]
    y_test = [entry[1] for entry in test_data]
    
    return X_train_full, y_train_full, X_test, y_test

# Set tokenization methods
tokenization_methods = ["basic", "ast", "normalize", "syntax", "cfg"]

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

# Normalize nested sequences during token loading
def normalize_sequences(sequences):
    return [
        [token for sublist in sequence for token in sublist] if sequence and isinstance(sequence[0], list) else sequence or ["<UNK>"]
        for sequence in sequences
    ]

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

# Step 1: Load and preprocess the data
X_train_full, y_train_full, X_test, y_test = load_data_for_method("basic")  # Change to method as needed
# ["basic", "ast", "normalize", "syntax", "cfg"]
vocab = build_vocab(X_train_full)
max_length = 100  # Set max length for sequences
X_train_encoded = encode_sequences(X_train_full, vocab, max_length)
X_test_encoded = encode_sequences(X_test, vocab, max_length)

# Step 2: Create DQN environment
# Assuming `create_env` returns a gym environment for DQN
env = create_env(X_train_encoded, y_train_full)

# Initialize the DQN model with updated hyperparameters
# Adding improvements for better performance

model = DQN(
    "MlpPolicy", 
    env, 
    verbose=1,
    buffer_size=100000,  # Increased to store more experiences
    learning_starts=2000,  # Start training after observing more transitions
    batch_size=64,  # Keeping the batch size
    gamma=0.99,  # Discount factor, keep stable for long-term rewards
    tau=0.005,  # Lower tau for more stable target updates
    train_freq=4,  # Update every 4 steps
    target_update_interval=100,  # Update target network less frequently
    exploration_fraction=0.2,  # Longer exploration period
    exploration_initial_eps=1.0,  # Start with full exploration
    exploration_final_eps=0.01,  # Reduce exploration gradually
    policy_kwargs={
        "net_arch": [128, 128, 64],  # Deeper network for learning complex patterns
        "activation_fn": nn.ReLU  # Non-linearity for better feature representation
    },
    learning_rate=1e-4,  # Reduce learning rate for better convergence
    optimize_memory_usage=False,
    seed=42  # Set seed for reproducibility
)

# Train for an optimal number of time steps
# Observing previous results, keep around 400k to prevent overfitting
model.learn(total_timesteps=400000)

# Save the trained model
model.save("improved_dqn_model")

# Evaluate the model on test data
train_and_eval_dqn(model, X_train_encoded, y_train_full, X_test_encoded, y_test)

# Evaluate metrics: ROC and PRC Curves
y_pred_prob = model.predict(X_test_encoded, deterministic=True)[0]
fpr, tpr, _ = roc_curve(y_test, y_pred_prob)
roc_auc = auc(fpr, tpr)

precision, recall, _ = precision_recall_curve(y_test, y_pred_prob)
prc_auc = auc(recall, precision)

# Save ROC Curve to file
roc_curve_file = "improved_roc_curve.png"
plt.figure(figsize=(10, 6))
plt.plot(fpr, tpr, color='blue', lw=2, label=f'ROC curve (area = {roc_auc:.2f})')
plt.plot([0, 1], [0, 1], color='gray', lw=2, linestyle='--')
plt.xlim([0.0, 1.0])
plt.ylim([0.0, 1.05])
plt.xlabel('False Positive Rate')
plt.ylabel('True Positive Rate')
plt.title('Receiver Operating Characteristic (ROC) Curve')
plt.legend(loc="lower right")
plt.savefig(roc_curve_file)
plt.close()

# Save Precision-Recall Curve to file
prc_curve_file = "improved_prc_curve.png"
plt.figure(figsize=(10, 6))
plt.plot(recall, precision, color='blue', lw=2, label=f'PRC curve (area = {prc_auc:.2f})')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.title('Precision-Recall Curve')
plt.legend(loc="lower left")
plt.savefig(prc_curve_file)
plt.close()

# Save metrics report to file
metrics_report_file = "improved_metrics_report.txt"
with open(metrics_report_file, 'w') as f:
    f.write(f"Improved ROC AUC: {roc_auc:.2f}\n")
    f.write(f"Improved PRC AUC: {prc_auc:.2f}\n")
    f.write(f"\nImproved ROC Curve saved to: {roc_curve_file}\n")
    f.write(f"Improved Precision-Recall Curve saved to: {prc_curve_file}\n")

print(f"Improved metrics report saved to {metrics_report_file}")


# Training Accuracy: 96.46%
# Test Accuracy: 41.46%

# Improved ROC AUC: 0.41
# Improved PRC AUC: 0.62

# Basically performmed terribly, worse than random for ROC curve