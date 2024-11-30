import os
import re
import json
import ast
import networkx as nx

# Define token mappings
TOKEN_TYPE_MAP = {
    "KEYWORD": 1,
    "SYMBOL": 2,
    "NUMBER": 3,
    "FUNCTION": 4,
    "IDENTIFIER": 5,
    "UNK": 6
}

# Define token categories
KEYWORDS = {'int', 'float', 'return', 'if', 'else', 'for', 'while', 'void', 'size_t', 'char', 'const', 'volatile', 'unsigned'}
SYMBOLS = {'(', ')', '{', '}', '[', ']', ';', ',', '->', '++', '--', '=', '==', '!=', '<', '>', '<=', '>=', '+', '-', '*', '/', '%', '&', '|', '^', '~', '!', '<<', '>>'}
FUNCTIONS = {'strcpy', 'memcpy', 'malloc', 'free', 'printf', 'fgets', 'strlen', 'strncpy', 'explicit_bzero'}
UNK = TOKEN_TYPE_MAP["UNK"]

# Regex patterns for token categories
NUMBER_PATTERN = r'\b\d+\b'
IDENTIFIER_PATTERN = r'\b[A-Za-z_][A-Za-z0-9_]*\b'

# Tokenization methods
def tokenize_ast(code):
    """Tokenize code into AST node types."""
    def visit_node(node):
        if isinstance(node, ast.AST):
            tokens.append(type(node).__name__)  # Node type as token
            for child in ast.iter_child_nodes(node):
                visit_node(child)

    tokens = []
    try:
        tree = ast.parse(code)
        visit_node(tree)
    except Exception as e:
        print(f"Error parsing AST: {e}")
        tokens.append("UNK")
    return tokens

def normalize_identifiers(code):
    """Replace variable and function names with placeholders."""
    return re.sub(r'\b[A-Za-z_][A-Za-z0-9_]*\b', 'IDENTIFIER', code)

def syntax_aware_tokenize(code):
    """Tokenize code by recognizing keywords, operators, and identifiers."""
    tokens = []
    words = re.findall(r'\w+|\S', code)  # Splits into words and symbols
    for word in words:
        if word in KEYWORDS:
            tokens.append("KEYWORD")
        elif word in SYMBOLS:
            tokens.append("SYMBOL")
        elif re.fullmatch(NUMBER_PATTERN, word):
            tokens.append("NUMBER")
        elif word in FUNCTIONS:
            tokens.append("FUNCTION")
        elif re.fullmatch(IDENTIFIER_PATTERN, word):
            tokens.append("IDENTIFIER")
        else:
            tokens.append("UNK")
    return tokens

def generate_cfg(code):
    """Generate a control flow graph (CFG) from code."""
    G = nx.DiGraph()
    # Placeholder implementation
    try:
        G.add_edges_from([
            ("Start", "If Condition"),
            ("If Condition", "Branch 1"),
            ("If Condition", "Branch 2"),
            ("Branch 1", "End"),
            ("Branch 2", "End")
        ])
        return list(G.edges)
    except Exception as e:
        print(f"Error generating CFG: {e}")
        return ["UNK"]

# Main tokenizer
def tokenize_code(code, method="basic"):
    """
    Tokenize code based on the selected method.

    Args:
        code (str): Input code snippet.
        method (str): Tokenization method ("basic", "ast", "normalize", "syntax", "cfg").

    Returns:
        List[int]: Tokenized code.
    """
    if method == "ast":
        return tokenize_ast(code)
    elif method == "normalize":
        normalized_code = normalize_identifiers(code)
        return tokenize_code(normalized_code, method="basic")
    elif method == "syntax":
        return syntax_aware_tokenize(code)
    elif method == "cfg":
        return generate_cfg(code)
    else:  # Default to basic tokenization
        tokens = []
        words = re.findall(r'\w+|\S', code)  # Splits into words and symbols
        for word in words:
            if word in KEYWORDS:
                tokens.append(TOKEN_TYPE_MAP["KEYWORD"])
            elif word in SYMBOLS:
                tokens.append(TOKEN_TYPE_MAP["SYMBOL"])
            elif re.fullmatch(NUMBER_PATTERN, word):
                tokens.append(TOKEN_TYPE_MAP["NUMBER"])
            elif word in FUNCTIONS:
                tokens.append(TOKEN_TYPE_MAP["FUNCTION"])
            elif re.fullmatch(IDENTIFIER_PATTERN, word):
                tokens.append(TOKEN_TYPE_MAP["IDENTIFIER"])
            else:
                tokens.append(UNK)
        return tokens

# Save data to JSON
def save_as_json(output_file, tokens, label):
    """Save tokens and their label to a JSON file."""
    data = {
        "tokens": tokens,
        "label": label
    }
    with open(output_file, 'w', encoding='utf-8') as json_file:
        json.dump(data, json_file)
    print(f"Saved JSON: {output_file}")

# Tokenize a file
def tokenize_file(input_file, output_file_base, label, method="basic"):
    """Tokenizes a single file using the specified method."""
    with open(input_file, 'r', encoding='utf-8') as infile:
        code = infile.read()
    tokens = tokenize_code(code, method=method)
    save_as_json(f"{output_file_base}_{method}.json", tokens, label)

# Process a directory
def process_directory(input_dir, output_dir, label, method="basic"):
    """Tokenizes all files in input_dir and saves the tokenized files with labels to output_dir."""
    os.makedirs(output_dir, exist_ok=True)
    for root, _, files in os.walk(input_dir):
        for file in files:
            if file.endswith('.c'):
                input_path = os.path.join(root, file)
                base_filename = file.replace('.c', '')
                output_file_base = os.path.join(output_dir, base_filename)
                tokenize_file(input_path, output_file_base, label, method=method)

# Process test data
def process_test_directory(test_dir, vuln_output_dir, patched_output_dir, method="basic"):
    """Processes test data and dynamically separates vulnerable and clean files."""
    os.makedirs(vuln_output_dir, exist_ok=True)
    os.makedirs(patched_output_dir, exist_ok=True)

    for root, _, files in os.walk(test_dir):
        for file in files:
            if file.endswith('.c'):
                input_path = os.path.join(root, file)
                base_filename = file.replace('.c', '')

                # Determine label based on filename suffix
                if "CLEAN" in file.upper():
                    output_file_base = os.path.join(patched_output_dir, base_filename)
                    label = 0  # Non-vulnerable
                else:
                    output_file_base = os.path.join(vuln_output_dir, base_filename)
                    label = 1  # Vulnerable

                tokenize_file(input_path, output_file_base, label, method=method)

# Main function
def main():
    # Directories for training and test data
    vuln_input_dir = "vuln_data"
    patched_input_dir = "patched_data"
    test_dir = "TestCode"

    # Output directories
    methods = ["basic", "ast", "normalize", "syntax", "cfg"]

    for method in methods:
        print(f"Tokenizing with method: {method}...")

        # Training data
        process_directory(vuln_input_dir, f"vuln_train_{method}", label=1, method=method)
        process_directory(patched_input_dir, f"patched_train_{method}", label=0, method=method)

        # Test data
        process_test_directory(
            test_dir,
            f"vuln_test_{method}",
            f"patched_test_{method}",
            method=method
        )

if __name__ == "__main__":
    main()
