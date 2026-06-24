import requests
# from bs4 import BeautifulSoup

# url = "https:/playvalorant.com/en-us/news/game-updates/"

reponse = requests.get("https:/playvalorant.com/en-us/news/game-updates/").text
# soup = BeautifulSoup('reponse','lxml')
print(reponse)

# card = soup.find_all('div',class_='card-body')
#
# print(card)
