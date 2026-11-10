import json
import os
import time
from urllib.parse import urlparse

# 1. Swap standard requests for curl_cffi
from curl_cffi import requests

download_dir = "alina_media"
os.makedirs(download_dir, exist_ok=True)

# 2. Add your FRESH cookies obtained while the VPN is active
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Referer": "https://coomer.st/",
    "Accept": "image/avif,image/webp,image/apng,image/*,*/*;q=0.8",
    "Cookie": "__ddg8_=Vt3tTLrHgqS9rW68; __ddg10_=1793040552; __ddg9_=103.216.221.114" # CRITICAL
}

# 3. Initialize the session to impersonate Chrome
session = requests.Session(impersonate="chrome120")
session.headers.update(headers)

# Load your existing JSON file
with open("alina_posts.json", "r", encoding="utf-8") as f:
    all_posts = json.load(f)

def download_file(url, folder):
    filename = os.path.basename(urlparse(url).path)
    filepath = os.path.join(folder, filename)

    if os.path.exists(filepath):
        print(f"Skipping: {filename}")
        return

    print(f"Downloading: {filename}...")
    try:
        # Use the impersonating session
        res = session.get(url, stream=True, timeout=60)
        
        if res.status_code == 200:
            with open(filepath, 'wb') as f:
                for chunk in res.iter_content(chunk_size=8192):
                    f.write(chunk)
            print(" -> Success")
        else:
            print(f" -> Failed (Status {res.status_code})")
    except Exception as e:
        print(f" -> Error: {e}")
        
    time.sleep(1.5)

print("Testing first 5 posts...")
for post in all_posts[:5]:
    if post.get("file") and post["file"].get("path"):
        main_url = f"https://coomer.st{post['file']['path']}"
        download_file(main_url, download_dir)
        
    for att in post.get("attachments", []):
        if att.get("path"):
            att_url = f"https://coomer.st{att['path']}"
            download_file(att_url, download_dir)
