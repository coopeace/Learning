from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
  def handle_comment(self,data):
    single = ">>> Single-line Comment"
    multi = ">>> Multi-line Comment"
    print(multi if '\n' in data else single) 
    print(data)
  def handle_data(self,data):
    if data == '\n': return
    print(">>> Data")
    print(data)
   
html = ""       
for i in range(int(input())):
    html += input().rstrip()
    html += '\n'
    
parser = MyHTMLParser()
parser.feed(html)
parser.close()
