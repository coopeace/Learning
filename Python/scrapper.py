from bs4 import BeautifulSoup

with open('test.html','r') as page:
    content = page.read()

    soup = BeautifulSoup(content,'lxml')
    # test_file_tags = soup.find_all('h2')

    # for tag in test_file_tags:
        # print(tag.text)

    tiers = soup.find_all('span',class_='font-label-caps text-[10px] bg-surface-container-high text-on-surface-variant px-2 py-0.5 rounded border border-outline/20')
    
    agents = soup.find_all('h3')

    for agent,tier in zip(agents,tiers):
        print(f"{agent.text} is {tier.text}")
