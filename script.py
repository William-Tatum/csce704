import re
from openai import OpenAI
from difflib import SequenceMatcher

client = OpenAI(api_key="sk-svcacct-kPyRL1I2gCx0-6gW5EH5MXT3upS_euCjuQf1uaNp776BDzVWv_ixUja__XSf9Y1T3BlbkFJjfIKXBKnz-CBdOBMbxRMIQ4cpyuRQSYygrhC5AivGPeZ18ATUP3yy4XzCJtbZAA")

def parse_cwe_file(file_path):
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

def query_chatgpt(cwe_title, cwe_description, cwe_extended_description):
    prompt = (f"Create a snippet of C code based on the following details (it must be written in C):\n"
              f"Title: {cwe_title}\n"
              f"Description: {cwe_description}\n"
              f"Extended Description: {cwe_extended_description}\n"
              "Ensure that you only print the code and nothing else as it will be going into a .txt file.\n"
              "Do not include comments and do not include markdown.\n")

    response = client.chat.completions.create(model="gpt-4o",
        messages=[
            {"role": "system", "content": "You are an expert in creating vulnerable code and identifying vulnerabilities. Think through this step by step to get to the right answer."},
            {"role": "user", "content": prompt}
        ])
    
    code = response.choices[0].message.content
    code = re.sub(r"```[a-zA-Z]*\n|```", "", code)
    return code

def similarity(a, b):
    return SequenceMatcher(None, a, b).ratio()

def vote_best_response(responses):
    score_matrix = [[similarity(a, b) for b in responses] for a in responses]
    scores = [sum(score_row) for score_row in score_matrix]
    best_index = scores.index(max(scores))
    return responses[best_index]

def main():
    cwe_data = parse_cwe_file('cwe_descriptions.txt')

    with open('output.txt', 'w', encoding='utf-8') as output_file, open('labels.txt', 'w', encoding='utf-8') as labels_file:
        for title, description, extended_description in cwe_data:
            print(f"\nProcessing CWE: {title}\n")
            responses = [query_chatgpt(title, description, extended_description) for _ in range(3)]
            print("Responses:\n", responses)

            best_response = vote_best_response(responses)

            # Write the CWE title to labels.txt
            labels_file.write(f"{title}\n")

            # Write the best response to output.txt
            output_file.write(f"{best_response}\n")
            output_file.write("\n" + "-"*80 + "\n\n")

if __name__ == "__main__":
    main()
