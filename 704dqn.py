import json
import random
from copy import deepcopy
from collections import deque

import torch
import torch.nn as nn
import torch.nn.functional as F
import numpy as np
from torch.optim import AdamW
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score

# Load preprocessed data
with open('processed_data.json', 'r') as infile:
    data = json.load(infile)

X = np.array(data['sequences'])  # Tokenized and padded sequences
y = np.array(data['labels'])     # Corresponding labels (1 for vulnerable)

# Split data into training and validation sets
X_train, X_val, y_train, y_val = train_test_split(X, y, test_size=0.2, random_state=42)


class QFunction(nn.Module):
    def __init__(self, obs_dim, act_dim, hidden_sizes):
        super().__init__()
        sizes = [obs_dim] + hidden_sizes + [act_dim]
        self.layers = nn.ModuleList()
        for i in range(len(sizes) - 1):
            self.layers.append(nn.Linear(sizes[i], sizes[i + 1]))

    def forward(self, obs):
        x = torch.cat([obs], dim=-1)
        for i in range(len(self.layers) - 1):
            x = F.relu(self.layers[i](x))
        return self.layers[-1](x).squeeze(dim=-1)


class DQN:
    def __init__(self, obs_dim, act_dim, options):
        self.model = QFunction(obs_dim, act_dim, options['layers'])
        self.target_model = deepcopy(self.model)
        self.optimizer = AdamW(self.model.parameters(), lr=options['alpha'], amsgrad=True)
        self.loss_fn = nn.SmoothL1Loss()

        # Freeze target network parameters
        for p in self.target_model.parameters():
            p.requires_grad = False

        self.replay_memory = deque(maxlen=options['replay_memory_size'])
        self.options = options
        self.n_steps = 0

    def update_target_model(self):
        self.target_model.load_state_dict(self.model.state_dict())

    def memorize(self, state, action, reward, next_state, done):
        self.replay_memory.append((state, action, reward, next_state, done))

    def compute_target_values(self, next_states, rewards, dones):
        return rewards + self.options['gamma'] * torch.max(self.target_model(next_states), dim=-1)[0] * (1 - dones)

    def replay(self):
        if len(self.replay_memory) > self.options['batch_size']:
            minibatch = random.sample(self.replay_memory, self.options['batch_size'])
            states, actions, rewards, next_states, dones = zip(*minibatch)

            states = torch.as_tensor(states, dtype=torch.float32)
            actions = torch.as_tensor(actions, dtype=torch.long)
            rewards = torch.as_tensor(rewards, dtype=torch.float32)
            next_states = torch.as_tensor(next_states, dtype=torch.float32)
            dones = torch.as_tensor(dones, dtype=torch.float32)

            current_q = self.model(states).gather(1, actions.unsqueeze(1)).squeeze(-1)
            with torch.no_grad():
                target_q = self.compute_target_values(next_states, rewards, dones)

            loss = self.loss_fn(current_q, target_q)
            self.optimizer.zero_grad()
            loss.backward()
            torch.nn.utils.clip_grad_value_(self.model.parameters(), 100)
            self.optimizer.step()

    def train(self, X_train, y_train):
        for epoch in range(self.options['epochs']):
            for i in range(len(X_train)):
                state = X_train[i]
                action = y_train[i]
                reward = 1 if action == 1 else -1  # Reward based on label
                next_state = state  # No transition in supervised setup
                done = True

                self.memorize(state, action, reward, next_state, done)
                self.replay()

                if self.n_steps % self.options['update_target_estimator_every'] == 0:
                    self.update_target_model()

                self.n_steps += 1

            print(f"Epoch {epoch + 1} completed.")

    def evaluate(self, X_val, y_val):
        self.model.eval()
        with torch.no_grad():
            predictions = []
            for i in range(len(X_val)):
                state = torch.as_tensor(X_val[i], dtype=torch.float32).unsqueeze(0)
                q_values = self.model(state)
                predicted_action = torch.argmax(q_values).item()
                predictions.append(predicted_action)

        accuracy = accuracy_score(y_val, predictions)
        print(f"Validation Accuracy: {accuracy:.4f}")
        self.model.train()

    def __str__(self):
        return "DQN"


# Define options for the DQN
options = {
    'layers': [128, 64],
    'alpha': 0.001,
    'gamma': 0.99,
    'replay_memory_size': 10000,
    'batch_size': 32,
    'update_target_estimator_every': 100,
    'epochs': 10
}

# Initialize and train the model
obs_dim = X_train.shape[1]
act_dim = 2  # Binary classification (0 or 1)
dqn = DQN(obs_dim, act_dim, options)

dqn.train(X_train, y_train)
dqn.evaluate(X_val, y_val)
