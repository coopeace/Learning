from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        print(tag)
        if len(attrs) > 0 :
            for attr in attrs:
                print("->",attr[0],">",attr[1])

parser = MyHTMLParser()

html = ""
n = int(input())
for _ in range(0,n):
    html += input()
    html += '\n'

parser.feed(html)
