import selenium.webdriver as webdriver
from selenium.webdriver.chrome.service import Service
from bs4 import BeautifulSoup
from openai import OpenAI
import time

client = OpenAI(api_key="")


def scrape_website(website):
    chrome_driver_path = "chromedriver.exe"
    options = webdriver.ChromeOptions()
    driver = webdriver.Chrome(service=Service(chrome_driver_path),options=options)
    driver.get(website)
    try:
        driver.get(website)
        time.sleep(5)
        html = driver.page_source
        return html
    finally:
        driver.quit()


def extract_body_content(html_content):
    soup = BeautifulSoup(html_content, "html.parser")
    body_content = soup.body
    if body_content:
        return str(body_content)
    return ""


def clean_body_content(body_content):
    soup = BeautifulSoup(body_content, "html.parser")

    for script_or_style in soup(["script", "style"]):
        script_or_style.extract()
        
    cleaned_content = soup.get_text(separator="\n")
    cleaned_content = "\n".join(
        line.strip() for line in cleaned_content.splitlines() if line.strip()
    )

    return cleaned_content


def split_dom_content(dom_content, max_length=6000):
    return [
        dom_content[i : i + max_length] for i in range(0, len(dom_content), max_length)
    ]


URL  = input("Enter the website URL: ")
URL_content = clean_body_content(extract_body_content(scrape_website(URL)))


prompt = "try to find all the important information about the professor"
message = f"You are tasked with extracting specific information from the following text content: {URL_content}. " \
          "Please follow these instructions carefully: \n\n" \
          f"1. **Extract Information:** Only extract the information that directly matches the provided description: {prompt}. " \
          "2. **No Extra Content:** Do not include any additional text, comments, or explanations in your response. " \
          "3. **Empty Response:** If no information matches the description, return an empty string (''). " \
          "4. **Direct Data Only:** Your output should contain only the data that is explicitly requested, with no other text."

print(message)

response = client.chat.completions.create(
                model="gpt-4o",
                messages=[
                    {"role": "system", "content": template},
                    {"role": "user", "content": message}
                ],
                max_tokens=100,
                temperature=0.7
            )
print(response.choices[0].message.content)

