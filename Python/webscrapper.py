import requests
from bs4 import BeautifulSoup

keywords = "python"

url = f"https://internshala.com/internships/keywords-{keywords}"

html_page = requests.get(url).text
soup = BeautifulSoup(html_page,'lxml')
post_titles = soup.find_all('a',class_ = 'job-title-href')
for title in post_titles:
    print(title.text)
    
