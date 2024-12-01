import gym
import numpy as np
from stable_baselines3 import DQN
from sklearn.metrics import accuracy_score

# Function to create the custom environment for DQN
def create_env(X_train_encoded, y_train_full):
    """
    Create a custom environment for training DQN.

    Args:
        X_train_encoded: The tokenized and encoded training sequences.
        y_train_full: The labels for the training data.

    Returns:
        env: A gym environment for DQN.
    """
    class CustomEnv(gym.Env):
        def __init__(self, X_train_encoded, y_train_full):
            super(CustomEnv, self).__init__()
            self.X = X_train_encoded
            self.y = y_train_full
            self.current_idx = 0
            self.action_space = gym.spaces.Discrete(2)  # Assume binary classification (patched or vulnerable)
            self.observation_space = gym.spaces.Box(low=0, high=1, shape=(X_train_encoded.shape[1],), dtype=np.float32)
        
        def reset(self):
            self.current_idx = 0
            return self.X[self.current_idx]
        
        def step(self, action):
            reward = 1 if action == self.y[self.current_idx] else -1
            self.current_idx += 1
            done = self.current_idx >= len(self.X)
            next_state = self.X[self.current_idx] if not done else np.zeros_like(self.X[0])
            return next_state, reward, done, {}

        def render(self, mode='human'):
            pass

    env = CustomEnv(X_train_encoded, y_train_full)
    return env


# Function to train and evaluate the DQN model
def train_and_eval_dqn(model, X_train_encoded, y_train_full, X_test_encoded, y_test):
    """
    Train the DQN model and evaluate its performance.

    Args:
        model: The DQN model.
        X_train_encoded: The tokenized and encoded training sequences.
        y_train_full: The labels for the training data.
        X_test_encoded: The encoded test data.
        y_test: The labels for the test data.

    Returns:
        None: Outputs evaluation metrics and saves the model.
    """
    # Train the model
    model.learn(total_timesteps=100000)  # Change timesteps if necessary
    
    # Predict on the training set
    train_preds = model.predict(X_train_encoded, deterministic=True)[0]
    train_accuracy = accuracy_score(y_train_full, train_preds)

    # Predict on the test set
    test_preds = model.predict(X_test_encoded, deterministic=True)[0]
    test_accuracy = accuracy_score(y_test, test_preds)
    
    # Print evaluation results
    print(f"Training Accuracy: {train_accuracy * 100:.2f}%")
    print(f"Test Accuracy: {test_accuracy * 100:.2f}%")
    
    return train_accuracy, test_accuracy
