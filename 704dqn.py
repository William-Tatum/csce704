import os
import time
import json
import random
from copy import deepcopy
from collections import deque
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from sklearn.metrics import (
    classification_report,
    roc_curve,
    auc,
    precision_recall_curve,
    average_precision_score,
)
import matplotlib.pyplot as plt
from torch.optim import AdamW

start = time.time()

# Directory for saving metrics and charts
output_dir = "dqn_metrics_output3"
os.makedirs(output_dir, exist_ok=True)

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

# Normalize nested sequences and build vocabulary
def normalize_sequences(sequences):
    return [
        [token for sublist in sequence for token in sublist] if sequence and isinstance(sequence[0], list) else sequence or ["<UNK>"]
        for sequence in sequences
    ]

def build_vocab(X_train_full):
    vocab = {"<PAD>": 0, "<UNK>": 1}
    current_id = 2
    for sequence in X_train_full:
        for token in (token for sublist in sequence for token in sublist) if isinstance(sequence[0], list) else sequence:
            if token not in vocab:
                vocab[token] = current_id
                current_id += 1
    return vocab

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

# Double DQN
class QFunction(nn.Module):
    def __init__(self, obs_dim, act_dim, hidden_sizes):
        super().__init__()
        sizes = [obs_dim] + hidden_sizes + [act_dim]
        self.layers = nn.ModuleList([nn.Linear(sizes[i], sizes[i + 1]) for i in range(len(sizes) - 1)])

    def forward(self, obs):
        x = obs
        for layer in self.layers[:-1]:
            x = F.relu(layer(x))
        return self.layers[-1](x)

class DQN:
    def __init__(self, obs_dim, act_dim, options):
        self.model = QFunction(obs_dim, act_dim, options['hidden_sizes'])
        self.target_model = deepcopy(self.model)
        self.optimizer = AdamW(self.model.parameters(), lr=options['lr'])
        self.loss_fn = nn.SmoothL1Loss()
        self.memory = deque(maxlen=options['memory_size'])
        self.gamma = options['gamma']
        self.batch_size = options['batch_size']
        self.target_update_freq = options['target_update_freq']
        self.n_steps = 0

    def memorize(self, state, action, reward, next_state, done):
        self.memory.append((state, action, reward, next_state, done))

    def train_step(self):
        if len(self.memory) < self.batch_size:
            return
        batch = random.sample(self.memory, self.batch_size)
        states, actions, rewards, next_states, dones = zip(*batch)
        states = torch.tensor(states, dtype=torch.float32)
        actions = torch.tensor(actions, dtype=torch.long)
        rewards = torch.tensor(rewards, dtype=torch.float32)
        next_states = torch.tensor(next_states, dtype=torch.float32)
        dones = torch.tensor(dones, dtype=torch.float32)

        # Double DQN: Get the Q-values for next state from the model, then use target network for target Q-values
        q_values = self.model(states).gather(1, actions.view(-1, 1)).squeeze()
        with torch.no_grad():
            next_q_values = self.model(next_states).max(1)[1]  # Get the best action from model
            target_q_values = self.target_model(next_states).gather(1, next_q_values.view(-1, 1)).squeeze()
            target_q_values = rewards + (1 - dones) * self.gamma * target_q_values

        loss = self.loss_fn(q_values, target_q_values)
        self.optimizer.zero_grad()
        loss.backward()
        self.optimizer.step()

        if self.n_steps % self.target_update_freq == 0:
            self.target_model.load_state_dict(self.model.state_dict())
        self.n_steps += 1

    def evaluate(self, X_test, y_test, vocab, max_length):
        X_test_encoded = encode_sequences(normalize_sequences(X_test), vocab, max_length)
        y_probs = []
        y_pred = []
        self.model.eval()
        with torch.no_grad():
            for state in torch.tensor(X_test_encoded, dtype=torch.float32):
                q_values = self.model(state.unsqueeze(0))
                probs = torch.softmax(q_values, dim=-1).squeeze()
                y_probs.append(probs[1].item())
                y_pred.append(probs.argmax().item())
        y_probs = np.array(y_probs)
        y_pred = np.array(y_pred)

        # Save metrics and charts
        report = classification_report(y_test, y_pred, target_names=["Non-vulnerable", "Vulnerable"])
        with open(os.path.join(output_dir, "classification_report.txt"), "w") as f:
            f.write(report)

        # ROC curve
        fpr, tpr, _ = roc_curve(y_test, y_probs)
        roc_auc = auc(fpr, tpr)
        plt.figure()
        plt.plot(fpr, tpr, label=f"ROC curve (area = {roc_auc:.2f})")
        plt.plot([0, 1], [0, 1], color="navy", linestyle="--")
        plt.xlabel("False Positive Rate")
        plt.ylabel("True Positive Rate")
        plt.title("Receiver Operating Characteristic")
        plt.legend(loc="lower right")
        plt.savefig(os.path.join(output_dir, "roc_curve.png"))
        plt.close()

        # PRC curve
        precision, recall, _ = precision_recall_curve(y_test, y_probs)
        avg_precision = average_precision_score(y_test, y_probs)
        plt.figure()
        plt.step(recall, precision, where="post", label=f"Avg Precision = {avg_precision:.2f}")
        plt.xlabel("Recall")
        plt.ylabel("Precision")
        plt.title("Precision-Recall Curve")
        plt.legend(loc="lower left")
        plt.savefig(os.path.join(output_dir, "prc_curve.png"))
        plt.close()

# Parameters and training loop
options = {'hidden_sizes': [128, 64], 'lr': 0.001, 'gamma': 0.99, 'memory_size': 5000, 'batch_size': 32, 'target_update_freq': 100}
method = "basic"
X_train, y_train, X_test, y_test = load_data_for_method(method)
vocab = build_vocab(normalize_sequences(X_train))
max_length = 100
X_train_encoded = encode_sequences(normalize_sequences(X_train), vocab, max_length)
X_test_encoded = encode_sequences(normalize_sequences(X_test), vocab, max_length)
obs_dim = X_train_encoded.shape[1]
act_dim = 2
dqn = DQN(obs_dim, act_dim, options)

for epoch in range(10):
    for i in range(len(X_train_encoded)):
        state = X_train_encoded[i]
        action = y_train[i]
        reward = 1 if action == 1 else -1
        next_state = state
        done = True
        dqn.memorize(state, action, reward, next_state, done)
        dqn.train_step()

dqn.evaluate(X_test, y_test, vocab, max_length)

end = time.time()

print(f"Time: {end-start}")

# Orginal 
# 10 Epochs = 19.26 (dqn_metrics_output)
# 100 Epochs = 240.5 (dqn_metrics_output2)

# Modified w/ DDQN
# 10 Epochs = 20.2 (dqn_metrics_output3)
# 100 Epochs = 814 (dqn_metrics_output4)
