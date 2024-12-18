import os
import json
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import roc_curve, roc_auc_score, precision_recall_curve, auc
from stable_baselines3 import DQN
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
X_train_full = normalize_sequences(X_train_full)
X_test = normalize_sequences(X_test)

vocab = build_vocab(X_train_full)

max_length = 512 # For sequences
X_train_encoded = encode_sequences(X_train_full, vocab, max_length)
X_test_encoded = encode_sequences(X_test, vocab, max_length)

# Step 2: Create DQN environment
# Assuming `create_env` returns a gym environment for DQN
env = create_env(X_train_encoded, y_train_full)

# Step 3: Initialize the DQN model with hyperparameters
model = DQN(
    "MlpPolicy", 
    env, 
    verbose=1, 
    buffer_size=50000, 
    learning_starts=1000, 
    batch_size=64, 
    gamma=0.97, 
    tau=0.1,
    train_freq=4, 
    target_update_interval=100
)

# Training Accuracy: 96.46%
# Test Accuracy: 52.44%
# ROC AUC: 0.52
# PRC AUC: 0.65
# model = DQN(
#     "MlpPolicy", 
#     env, 
#     verbose=1, 
#     buffer_size=100000,  # Larger buffer to store more experiences
#     learning_starts=5000,  # Delay updates for better initial policy exploration
#     batch_size=128,  # Larger batch size for more stable gradients
#     gamma=0.995,  # Higher discount factor for longer-term rewards
#     tau=0.005,  # Lower tau for smoother target updates
#     train_freq=4, 
#     target_update_interval=100, 
#     exploration_fraction=0.2,  # Prolonged exploration phase
#     exploration_final_eps=0.01,  # Lower final epsilon for better exploitation
#     learning_rate=5e-4,  # Slightly increased learning rate
#     gradient_steps=-1  # Full training per step for stability
# )

# Start of notes for many runs of this code
# Orginal Results before modification - These are all for the basic data
# As shown in directory this report is saved to new_dqn_metrics_output1
# Training Accuracy: 91.52%
# Test Accuracy: 48.78%

# Decrease tau from 0.1 to 0.005 and increase from 100k to 200k time steps got these results:
# Training Accuracy: 95.85%
# Test Accuracy: 46.34%

# Moving tau back from 0.005 and keeping 200k time steps
# This is shown in new_dqn_metrics_output2
# Training Accuracy: 91.28%
# Test Accuracy: 52.44%

# Moving from 200k timesteps to 400k timesteps 
# This is shown in new_dqn_metrics_output3
# Training Accuracy: 95.18%
# Test Accuracy: 56.10%
# ROC AUC: 0.56
# PRC AUC: 0.67

# Moving from 400k timesteps to 800k timesteps - Overtrained
# This is shown in new_dqn_metrics_output4
# Training Accuracy: 95.61%
# Test Accuracy: 50%
# ROC AUC: 0.50
# PRC AUC: 0.62

# Moving from 800k to 500k timesteps - ROC/PRC curves not saved if file folder not mentioned
# Training Accuracy: 94.09%
# Test Accuracy: 48.78%

# Increase gamma from 0.99 to 0.995
# Training Accuracy: 88.96%
# Test Accuracy: 47.56%

# 0.995 with 400k timesteps
# Training Accuracy: 94.70%
# Test Accuracy: 51.22%
# Run 2:
# Training Accuracy: 93.11%
# Test Accuracy: 48.78%

# Change back to 0.99 with 400k timesteps
# Training Accuracy: 94.70%
# Test Accuracy: 54.88%

# Chagne to 0.98 gamma - BEST so far
# Training Accuracy: 95.55%
# Test Accuracy: 58.54%

# At 0.97 gamma -> Test Accuracy: 46.34%

# Up until now it has only been on basic data, with same metrics as "BEST so far" for BASIC using on *ast*
# This is with changing nothing that got the 58.54% for basic data
# ROC AUC: 0.48
# PRC AUC: 0.69 - Terrible performance, worse than 50/50 coin toss

# Now for *normalize*
# Test Accuracy: 39.02%
# ROC AUC: 0.39
# PRC AUC: 0.57

# Now for *syntax*
# Test Accuracy: 52.44%
# ROC AUC: 0.52
# PRC AUC: 0.65 - Slightly better but not great

# Now for *cfg*
# Currently index out of bounds error

# Step 4: Train the DQN model using the training data
model.learn(total_timesteps=400000)

# Step 5: Save the trained model
model.save("trained_dqn_model")

# Step 6: Evaluate the model
train_and_eval_dqn(model, X_train_encoded, y_train_full, X_test_encoded, y_test)

# Step 7: Evaluate metrics: ROC curve, PRC curve
y_pred_prob = model.predict(X_test_encoded, deterministic=True)[0]
fpr, tpr, _ = roc_curve(y_test, y_pred_prob)
roc_auc = auc(fpr, tpr)

precision, recall, _ = precision_recall_curve(y_test, y_pred_prob)
prc_auc = auc(recall, precision)

# Save ROC Curve to file
roc_curve_file = "roc_curve.png"
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
prc_curve_file = "prc_curve.png"
plt.figure(figsize=(10, 6))
plt.plot(recall, precision, color='blue', lw=2, label=f'PRC curve (area = {prc_auc:.2f})')
plt.xlabel('Recall')
plt.ylabel('Precision')
plt.title('Precision-Recall Curve')
plt.legend(loc="lower left")
plt.savefig(prc_curve_file)
plt.close()

# Save metrics report to file
metrics_report_file = "metrics_report.txt"
with open(metrics_report_file, 'w') as f:
    f.write(f"ROC AUC: {roc_auc:.2f}\n")
    f.write(f"PRC AUC: {prc_auc:.2f}\n")
    f.write(f"\nROC Curve saved to: {roc_curve_file}\n")
    f.write(f"Precision-Recall Curve saved to: {prc_curve_file}\n")

print(f"Metrics report saved to {metrics_report_file}")

