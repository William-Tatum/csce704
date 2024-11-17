import requests
from bs4 import BeautifulSoup

# List of CWE IDs
cwe_ids = [
    14, 119, 120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 134, 135, 
    170, 188, 191, 192, 194, 195, 196, 197, 242, 243, 244, 362, 364, 366, 374, 375,
    401, 415, 416, 457, 460, 462, 463, 464, 466, 467, 468, 469, 474, 476, 478, 479,
    480, 481, 482, 483, 484, 495, 496, 558, 560, 562, 587, 676, 685, 688, 689, 690, 
    704, 733, 762, 781, 782, 783, 785, 787, 789, 805, 806, 839, 843, 910, 911, 1325, 
    1335, 1341
]

# Function to scrape data for a specific CWE ID
def scrape_cwe(cwe_id):
    url = f"https://cwe.mitre.org/data/definitions/{cwe_id}.html"
    response = requests.get(url)
    if response.status_code == 200:
        soup = BeautifulSoup(response.content, 'html.parser')
        
        # Extract the title
        title = soup.title.string.strip() if soup.title else f"CWE-{cwe_id}: Title not found"
        # Clean the title to remove the extra spaces and version number in parentheses
        title = " ".join(soup.title.string.split()).replace("CWE - ", "").split("(")[0].strip()
        
        # Extract Description
        description_div = soup.find('div', id="Description")
        description = description_div.find('div', class_="indent").get_text(strip=True) if description_div else "Description not found"
        
        # Extract Extended Description
        extended_description_div = soup.find('div', id="Extended_Description")
        extended_description = extended_description_div.find('div', class_="indent").get_text(strip=True) if extended_description_div else "Extended Description not found"
        
        return title, description, extended_description
    else:
        print(f"Failed to retrieve CWE-{cwe_id}")
        return None, None, None


# File to store the results
output_file = "cwe_descriptions.txt"

# Scrape and save data
with open(output_file, "w", encoding="utf-8") as f:
    for cwe_id in cwe_ids:
        print(f"Proccessing CWE-{cwe_id}")
        title, description, extended_description = scrape_cwe(cwe_id)
        if description and extended_description:
            f.write(f"Title: {title}\n")
            f.write(f"Description: {description}\n")
            f.write(f"Extended Description: {extended_description}\n")
            f.write("\n" + "-"*80 + "\n\n")

print(f"Scraping completed. Descriptions saved to {output_file}")
