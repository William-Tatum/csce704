import os
import json
import numpy as np
from sklearn.model_selection import train_test_split
import tensorflow as tf
from keras.api.models import Sequential, Model
from keras.api.layers import Embedding, Conv1D, GlobalMaxPooling1D, Dense, Dropout, Input, Concatenate, LSTM, Bidirectional, Dot, Flatten, Layer, Activation, MultiHeadAttention, LayerNormalization
from keras.api.optimizers import Adam, SGD
from keras.api.optimizers.schedules import ExponentialDecay, CosineDecay
from keras.api.callbacks import LearningRateScheduler, Callback, ReduceLROnPlateau, EarlyStopping
from sklearn.metrics import classification_report, accuracy_score, precision_recall_curve, average_precision_score, roc_curve, auc
import matplotlib.pyplot as plt
import math

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
    """
    Builds a vocabulary from the training data.

    Args:
        X_train_full (list of lists): Tokenized training data.

    Returns:
        dict: Vocabulary mapping tokens to unique IDs.
    """
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

# Positional Encoding Layer
class PositionalEncoding(tf.keras.layers.Layer):
    def __init__(self, embedding_dim):
        super(PositionalEncoding, self).__init__()
        self.embedding_dim = embedding_dim

    def call(self, inputs):
        seq_length = tf.shape(inputs)[1]
        position = tf.range(seq_length, dtype=tf.float32)[:, tf.newaxis]
        div_term = tf.exp(tf.range(0, self.embedding_dim, 2, dtype=tf.float32) * -(np.log(10000.0) / self.embedding_dim))
        positional_encoding = tf.concat([tf.sin(position * div_term), tf.cos(position * div_term)], axis=1)
        positional_encoding = positional_encoding[tf.newaxis, ...]
        return inputs + positional_encoding[:, :seq_length, :]

# Transformer Encoder Layer
def transformer_encoder(inputs, num_heads, key_dim, ff_dim, dropout_rate):
    attention = MultiHeadAttention(num_heads=num_heads, key_dim=key_dim)(inputs, inputs)
    attention = Dropout(dropout_rate)(attention)
    attention = LayerNormalization(epsilon=1e-6)(inputs + attention)

    ff_output = Dense(ff_dim, activation="relu")(attention)
    ff_output = Dense(inputs.shape[-1])(ff_output)
    ff_output = Dropout(dropout_rate)(ff_output)
    return LayerNormalization(epsilon=1e-6)(attention + ff_output)

# Build the CNN-BiLSTM Model
def build_cnn_model(vocab_size, embedding_dim=256, num_filters=256, kernel_sizes=[3, 5, 7],
                    lstm_units=256, dense_units=256, dropout_rate=0.5, l2_lambda=0.01, num_heads=4):
    input_layer = Input(shape=(None,), dtype="int32")
    embedding = Embedding(input_dim=vocab_size, output_dim=embedding_dim, mask_zero=True)(input_layer)
    
    positional_encoding = PositionalEncoding(embedding_dim=embedding_dim)(embedding)
    transformer = transformer_encoder(positional_encoding, num_heads=num_heads, key_dim=embedding_dim, ff_dim=512, dropout_rate=0.1)
    
    conv_layers = []
    for kernel_size in kernel_sizes:
        conv = Conv1D(filters=num_filters, kernel_size=kernel_size, activation="relu", kernel_regularizer=tf.keras.regularizers.l2(l2_lambda))(transformer)
        pooled = GlobalMaxPooling1D()(conv)
        conv_layers.append(pooled)
    
    conv_features = Concatenate()(conv_layers)
    lstm = Bidirectional(LSTM(lstm_units, return_sequences=True, kernel_regularizer=tf.keras.regularizers.l2(l2_lambda)))(transformer)
    
    attention = Dense(1, activation="tanh")(lstm)
    attention = Flatten()(attention)
    attention_weights = tf.keras.layers.Activation("softmax")(attention)
    attention_output = tf.keras.layers.Dot(axes=1)([attention_weights, lstm])
    
    combined = Concatenate()([conv_features, attention_output])
    dense = Dense(dense_units, activation="relu", kernel_regularizer=tf.keras.regularizers.l2(l2_lambda))(combined)
    dropout = Dropout(dropout_rate)(dense)
    output = Dense(1, activation="sigmoid")(dropout)
    
    model = Model(inputs=input_layer, outputs=output)
    model.compile(optimizer=Adam(learning_rate=1e-4), loss="binary_crossentropy", metrics=["accuracy", tf.keras.metrics.AUC(name="auc")])
    return model

for method in tokenization_methods:
    print(f"Processing tokenization method: {method}")
    
    # Load data
    X_train_full, y_train_full, X_test, y_test = load_data_for_method(method)
    
    X_train_full = normalize_sequences(X_train_full)
    X_test = normalize_sequences(X_test)

    # Build vocabulary
    vocab = build_vocab(X_train_full)
    vocab_size = len(vocab)
    max_length = 512  # Set a fixed maximum sequence length
    
    # Encode sequences
    X_train_full_encoded = encode_sequences(X_train_full, vocab, max_length)
    X_test_encoded = encode_sequences(X_test, vocab, max_length)

    X_train, X_val, y_train, y_val = train_test_split(
        X_train_full_encoded, 
        np.array(y_train_full), 
        test_size=0.2, 
        random_state=42
    )
    y_test = np.array(y_test)
    
    # Build model
    cnn_model = build_cnn_model(vocab_size=vocab_size)
    
    # Callbacks
    early_stopping = EarlyStopping(monitor='val_loss', patience=5, restore_best_weights=True)
    reduce_lr_callback = ReduceLROnPlateau(monitor='val_loss', factor=0.5, patience=3, min_lr=1e-6)
    
    # Train model
    history = cnn_model.fit(
        X_train, 
        y_train, 
        validation_data=(X_val, y_val), 
        epochs=2,  # Use more epochs for better results
        batch_size=32, 
        callbacks=[early_stopping, reduce_lr_callback], 
        verbose=1
    )

    # Evaluate model
    y_pred_prob = cnn_model.predict(X_test_encoded, verbose=1)
    test_results = cnn_model.evaluate(X_test_encoded, y_test, verbose=1)
    
    # Compute ROC and PRC
    fpr, tpr, _ = roc_curve(y_test, y_pred_prob)
    roc_auc = auc(fpr, tpr)
    precision, recall, _ = precision_recall_curve(y_test, y_pred_prob)
    prc_auc = average_precision_score(y_test, y_pred_prob)

    # Plot ROC Curve
    plt.figure(figsize=(12, 5))
    plt.subplot(1, 2, 1)
    plt.plot(fpr, tpr, color='b', lw=2, label=f"AUC = {roc_auc:.4f}")
    plt.plot([0, 1], [0, 1], color='r', linestyle='--', label="Random Baseline")
    plt.title(f"{method.upper()} - ROC Curve")
    plt.xlabel("False Positive Rate")
    plt.ylabel("True Positive Rate")
    plt.legend()

    # Plot PRC Curve
    plt.subplot(1, 2, 2)
    plt.plot(recall, precision, color='b', lw=2, label=f"AP = {prc_auc:.4f}")
    plt.axhline(y=0.5, color='r', linestyle='--', label="Random Baseline")
    plt.title(f"{method.upper()} - Precision-Recall Curve")
    plt.xlabel("Recall")
    plt.ylabel("Precision")
    plt.legend()

    plt.tight_layout()
    plt.show()
