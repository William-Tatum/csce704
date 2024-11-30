import os
import re
from openai import OpenAI
from difflib import SequenceMatcher

# Initialize OpenAI client
client = OpenAI(api_key="sk-svcacct-kPyRL1I2gCx0-6gW5EH5MXT3upS_euCjuQf1uaNp776BDzVWv_ixUja__XSf9Y1T3BlbkFJjfIKXBKnz-CBdOBMbxRMIQ4cpyuRQSYygrhC5AivGPeZ18ATUP3yy4XzCJtbZAA")

def create_directories():
    """Ensure directories for vulnerable and patched examples exist."""
    os.makedirs("vuln_data", exist_ok=True)
    os.makedirs("patched_data", exist_ok=True)

def parse_cwe_file(file_path):
    """Parse CWE descriptions and return structured data."""
    cwe_data = []
    with open(file_path, 'r', encoding='utf-8') as file:
        content = file.read().strip().split("\n\n--------------------------------------------------------------------------------\n\n")
        for entry in content:
            lines = entry.split('\n')
            title = lines[0].replace("Title: ", "").strip()
            description = lines[1].replace("Description: ", "").strip()
            extended_description = lines[2].replace("Extended Description: ", "").strip() if len(lines) > 2 else ""
            cwe_data.append((title, description, extended_description))
    return cwe_data

def query_chatgpt(prompt):
    """Query ChatGPT API for code generation."""
    response = client.chat.completions.create(
        model="gpt-4o",
        messages=[
            {"role": "system", "content": "You are an expert in identifying and fixing vulnerabilities in code. Generate code snippets as per the instructions."},
            {"role": "user", "content": prompt}
        ]
    )
    code = response.choices[0].message.content
    code = re.sub(r"```[a-zA-Z]*\n|```", "", code)  # Clean markdown code formatting
    return code.strip()

def generate_vulnerable_code(title, description, extended_description):
    """Generate a vulnerable code snippet."""
    prompt = (f"Create a snippet of C code based on the following details (it must be written in C):\n"
              f"Title: {title}\n"
              f"Description: {description}\n"
              f"Extended Description: {extended_description}\n"
              "Ensure that you only print the code and nothing else as it will be going into a .txt file.\n"
              "Do not include comments and do not include markdown.\n")
    return query_chatgpt(prompt)

def generate_patched_code(vulnerable_code, title, description, extended_description):
    """Generate the patched version of the code."""
    prompt = (f"Given the following vulnerable code, fix the vulnerability:\n\n"
              f"{vulnerable_code}\n\n"
              "Make sure the patched code adheres to secure coding practices. "
              "Only output the fixed code without comments or markdown.")
    return query_chatgpt(prompt)

def similarity(a, b):
    """Calculate similarity ratio between two strings."""
    return SequenceMatcher(None, a, b).ratio()

def is_unique(code, existing_codes, threshold=0.8):
    """Check if the code is unique based on similarity threshold."""
    return all(similarity(code, existing) < threshold for existing in existing_codes)

def save_code_to_file(directory, title, example_num, code):
    """Save a code example to a file."""
    safe_title = re.sub(r'[^\w\s]', '', title).replace(' ', '_')
    filename = f"{directory}/{safe_title}_{example_num}.c"
    with open(filename, 'w', encoding='utf-8') as file:
        file.write(code)
    print(f"Saved: {filename}")

def main():
    create_directories()
    cwe_data = parse_cwe_file('cwe_descriptions.txt')

    for title, description, extended_description in cwe_data:
        print(f"Processing CWE: {title}")

        vulnerable_examples = []
        patched_examples = []

        for example_num in range(10):  # Generate 10 examples per CWE
            # Generate a unique vulnerable example
            while True:
                vulnerable_code = generate_vulnerable_code(title, description, extended_description)
                if is_unique(vulnerable_code, vulnerable_examples):
                    break
            vulnerable_examples.append(vulnerable_code)

            # Generate the corresponding patched example
            patched_code = generate_patched_code(vulnerable_code, title, description, extended_description)
            patched_examples.append(patched_code)

            # Save each example to separate files
            save_code_to_file("vuln_data", title, example_num, vulnerable_code)
            save_code_to_file("patched_data", title, example_num, patched_code)

if __name__ == "__main__":
    main()
