import re
import json
import tensorflow as tf
from keras.api.utils import pad_sequences

# Define categories
KEYWORDS = [
    "auto", "break", "case", "char", "const", "continue", "default", "do", "double",
    "else", "enum", "extern", "float", "for", "goto", "if", "inline", "int", "long",
    "register", "restrict", "return", "short", "signed", "sizeof", "static", "struct",
    "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
]
SYMBOLS = [
    r"\(", r"\)", r"\{", r"\}", r"\[", r"\]", r"\;", r"\,", r"\.", r"\+", r"\-", r"\*",
    r"\/", r"\%", r"\=", r"\<", r"\>", r"\&", r"\|", r"\!", r"\^", r"\~", r"\?",
    r"\:\:", r"\.\.", r"->", r"\+\+", r"--", r"<<", r">>", r"==", r"!=", r"<=", r">=", r"\|\|", r"&&", r"\+=",
    r"-=", r"\*=", r"\/=", r"\%="
]
FUNCTIONS = ["strcpy", "memcpy", "strlen", "strcat", "strcmp", "sprintf", "malloc", "free", "printf"]
TOKEN_TYPES = {
    "KEYWORD": 1,
    "SYMBOL": 2,
    "NUMBER": 3,
    "FUNCTION": 4,
    "IDENTIFIER": 5
}

# Regex patterns for token categories
KEYWORD_PATTERN = r'\b(' + '|'.join(KEYWORDS) + r')\b'
SYMBOL_PATTERN = '|'.join(SYMBOLS)
NUMBER_PATTERN = r'\b\d+\b'
FUNCTION_PATTERN = r'\b(' + '|'.join(FUNCTIONS) + r')\b'
IDENTIFIER_PATTERN = r'\b[a-zA-Z_]\w*\b'

def tokenize_code(code):
    """Tokenizes C code into categories and values."""
    tokenized = []
    token_specification = [
        ('KEYWORD', KEYWORD_PATTERN),
        ('SYMBOL', SYMBOL_PATTERN),
        ('NUMBER', NUMBER_PATTERN),
        ('FUNCTION', FUNCTION_PATTERN),
        ('IDENTIFIER', IDENTIFIER_PATTERN)
    ]
    combined_pattern = '|'.join(f'(?P<{key}>{pattern})' for key, pattern in token_specification)
    token_regex = re.compile(combined_pattern)
    
    for match in token_regex.finditer(code):
        kind = match.lastgroup
        value = match.group(kind)
        token_type = TOKEN_TYPES[kind]
        tokenized.append((token_type, value))
    
    return tokenized

def encode_tokens(tokenized_snippets):
    """Encodes tokens into numeric IDs using a vocabulary."""
    vocab = {"<PAD>": 0, "<UNK>": 1}
    for snippet in tokenized_snippets:
        for _, token_value in snippet:
            if token_value not in vocab:
                vocab[token_value] = len(vocab)
    
    encoded_snippets = [
        [vocab.get(token[1], vocab["<UNK>"]) for token in snippet]
        for snippet in tokenized_snippets
    ]
    return encoded_snippets, vocab

def preprocess_file(input_file, output_data_file, output_vocab_file, max_seq_length=100):
    """Processes the input file and saves tokenized, encoded, and padded data."""
    with open(input_file, 'r') as file:
        content = file.read()
    
    snippets = content.split('--------------------------------------------------------------------------------')
    
    # Tokenize snippets
    tokenized_snippets = [tokenize_code(snippet) for snippet in snippets if snippet.strip()]
    
    # Encode tokens
    encoded_snippets, vocab = encode_tokens(tokenized_snippets)
    
    # Pad sequences
    padded_sequences = pad_sequences(encoded_snippets, maxlen=max_seq_length, padding="post", truncating="post")
    
    # Assign labels (all snippets are vulnerable)
    labels = [1] * len(padded_sequences)
    
    # Save processed data
    processed_data = {
        "sequences": padded_sequences.tolist(),
        "labels": labels
    }
    with open(output_data_file, 'w') as outfile:
        json.dump(processed_data, outfile, indent=4)
    
    # Save vocabulary
    with open(output_vocab_file, 'w') as vocab_file:
        json.dump(vocab, vocab_file, indent=4)

if __name__ == "__main__":
    input_file_path = 'output.txt'
    output_data_file = 'processed_data.json'
    output_vocab_file = 'vocab.json'
    
    preprocess_file(input_file_path, output_data_file, output_vocab_file)
    print("Data preprocessing complete. Processed data saved to 'processed_data.json'. Vocabulary saved to 'vocab.json'.")
