import os
import re
import json
import networkx as nx
from clang.cindex import Index, Config

# Configure libclang path
Config.set_library_file('.venv/lib/python3.12/site-packages/clang/native/libclang.so')

# Define token mappings
TOKEN_TYPE_MAP = {
    "KEYWORD": 1,
    "SYMBOL": 2,
    "NUMBER": 3,
    "FUNCTION": 4,
    "IDENTIFIER": 5,
    "UNK": 6
}

KEYWORDS = {'int', 'float', 'return', 'if', 'else', 'for', 'while', 'void', 'size_t', 'char', 'const', 'volatile', 'unsigned'}
SYMBOLS = {'(', ')', '{', '}', '[', ']', ';', ',', '->', '++', '--', '=', '==', '!=', '<', '>', '<=', '>=', '+', '-', '*', '/', '%', '&', '|', '^', '~', '!', '<<', '>>'}
FUNCTIONS = {'strcpy', 'memcpy', 'malloc', 'free', 'printf', 'fgets', 'strlen', 'strncpy', 'explicit_bzero'}
UNK = TOKEN_TYPE_MAP["UNK"]

NUMBER_PATTERN = r'\b\d+\b'
IDENTIFIER_PATTERN = r'\b[A-Za-z_][A-Za-z0-9_]*\b'

def tokenize_ast(code):
    tokens = []
    try:
        with open("temp.c", "w") as temp_file:
            temp_file.write(code)
        index = Index.create()
        tu = index.parse("temp.c")
        def visit_node(node):
            if node.kind is not None:
                tokens.append(node.kind.name)
            for child in node.get_children():
                visit_node(child)
        visit_node(tu.cursor)
    except Exception as e:
        print(f"Error parsing AST: {e}")
        tokens.append("UNK")
    return tokens

def syntax_aware_tokenize(code):
    tokens = []
    words = re.findall(r'\w+|\S', code)
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
    """
    Generate a control flow graph (CFG) using libclang.
    Args:
        code (str): C code to analyze.
    Returns:
        list: List of edges representing the CFG.
    """
    G = nx.DiGraph()
    try:
        # Write the code to a temporary file for libclang to parse
        with open("temp.c", "w") as temp_file:
            temp_file.write(code)

        # Parse the code with libclang
        index = Index.create()
        tu = index.parse("temp.c")

        # Helper function to add nodes and edges
        def visit_node(node, parent=None):
            node_id = node.spelling or node.displayname or node.kind.name
            if not node_id:
                node_id = f"Node_{node.hash}"
            G.add_node(node_id, kind=node.kind.name)

            if parent is not None:
                G.add_edge(parent, node_id)

            # Recursively visit children
            for child in node.get_children():
                visit_node(child, node_id)

        # Start visiting from the root cursor
        visit_node(tu.cursor)

        # Return edges as a list for storage
        return list(G.edges)
    except Exception as e:
        print(f"Error generating CFG: {e}")
        return [("UNK", "UNK")]


def tokenize_code(code, method="basic"):
    if method == "ast":
        return tokenize_ast(code)
    elif method == "syntax":
        return syntax_aware_tokenize(code)
    elif method == "cfg":
        return generate_cfg(code)
    else:
        tokens = []
        words = re.findall(r'\w+|\S', code)
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

def save_as_json(output_file, tokens, label):
    data = {"tokens": tokens, "label": label}
    with open(output_file, 'w', encoding='utf-8') as json_file:
        json.dump(data, json_file)
    print(f"Saved JSON: {output_file}")

def tokenize_file(input_file, output_file_base, label, method="basic"):
    with open(input_file, 'r', encoding='utf-8') as infile:
        code = infile.read()
    tokens = tokenize_code(code, method=method)
    save_as_json(f"{output_file_base}_{method}.json", tokens, label)

def process_directory(input_dir, output_dir, label, method="basic"):
    os.makedirs(output_dir, exist_ok=True)
    for root, _, files in os.walk(input_dir):
        for file in files:
            if file.endswith('.c'):
                input_path = os.path.join(root, file)
                base_filename = file.replace('.c', '')
                output_file_base = os.path.join(output_dir, base_filename)
                tokenize_file(input_path, output_file_base, label, method=method)

def process_test_directory(test_dir, vuln_output_dir, patched_output_dir, method="basic"):
    os.makedirs(vuln_output_dir, exist_ok=True)
    os.makedirs(patched_output_dir, exist_ok=True)
    for root, _, files in os.walk(test_dir):
        for file in files:
            if file.endswith('.c'):
                input_path = os.path.join(root, file)
                base_filename = file.replace('.c', '')
                if "CLEAN" in file.upper():
                    output_file_base = os.path.join(patched_output_dir, base_filename)
                    label = 0
                else:
                    output_file_base = os.path.join(vuln_output_dir, base_filename)
                    label = 1
                tokenize_file(input_path, output_file_base, label, method=method)

def main():
    vuln_input_dir = "vuln_data"
    patched_input_dir = "patched_data"
    test_dir = "TestCode"
    methods = ["basic", "ast", "syntax", "cfg"]

    for method in methods:
        print(f"Tokenizing with method: {method}...")
        process_directory(vuln_input_dir, f"vuln_train_{method}", label=1, method=method)
        process_directory(patched_input_dir, f"patched_train_{method}", label=0, method=method)
        process_test_directory(test_dir, f"vuln_test_{method}", f"patched_test_{method}", method=method)

if __name__ == "__main__":
    main()
