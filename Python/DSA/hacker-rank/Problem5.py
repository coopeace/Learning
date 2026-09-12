from html.parser import HTMLParser

def handle_attributes(attrs):
  for attr in attrs:
    print("->",attr[0],">",attr[1])

class MYHTMLParser(HTMLParser):
        def handle_starttag(self,tag,attrs):
            print("Start :",tag)
            handle_attributes(attrs)
        def handle_endtag(self,tag):
            print("End   :",tag)
        def handle_startendtag(self, tag, attrs):
            print("Empty :",tag)
            handle_attributes(attrs)

parser = MYHTMLParser()

n = int(input())
str = ""

for i in range(0,n):
  str = input()
  parser.feed(str) 
