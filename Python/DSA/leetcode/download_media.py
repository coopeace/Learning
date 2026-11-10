import requests
import json
import time
import os
from urllib.parse import urlparse

# --- CONFIGURATION ---
service = "fansly"
creator_id = "354053760600776704"
download_dir = "alina_media"

headers = {
    "Accept": "text/css",
    "User-Agent": "Mozilla/5.0 (X11; Linux x86_64; rv:158.0) Gecko/20100101 Firefox/158.0",
    "Referer": f"https://coomer.st/{service}/user/{creator_id}",
    # IMPORTANT: Update these cookies before running!
    "Cookie": "__ddg8_=YOUR_COOKIE; __ddg10_=YOUR_COOKIE; __ddg9_=YOUR_COOKIE" 
}

# --- STEP 1: SCRAPE THE POST METADATA ---
all_posts = []
offset = 0
url_template = f"https://coomer.st/api/v1/{service}/user/{creator_id}/posts?o={{offset}}"

print("Starting scrape...")

while True:
    url = url_template.format(offset=offset)
    print(f"Fetching offset {offset}...")
    
    response = requests.get(url, headers=headers)
    
    if response.status_code == 404 and offset == 0:
        url_template = f"https://coomer.st/api/v1/{service}/user/{creator_id}?o={{offset}}"
        continue

    if response.status_code != 200:
        break
        
    data = response.json()
    posts_batch = data.get("posts", []) if isinstance(data, dict) else data
    
    if not posts_batch:
        break
        
    all_posts.extend(posts_batch)
    offset += 50
    time.sleep(1)

print(f"Scrape complete. Found {len(all_posts)} posts.")

# Save a backup of the metadata just in case
with open("alina_posts.json", "w", encoding="utf-8") as f:
    json.dump(all_posts, f, indent=4)
print("Saved metadata backup to alina_posts.json")

# --- STEP 2: DOWNLOAD THE MEDIA ---
os.makedirs(download_dir, exist_ok=True)

def download_file(url, folder):
    filename = os.path.basename(urlparse(url).path)
    filepath = os.path.join(folder, filename)

    if os.path.exists(filepath):
        print(f"Skipping (already downloaded): {filename}")
        return

    print(f"Downloading: {filename}...")
    try:
        res = requests.get(url, headers=headers, stream=True)
        if res.status_code == 200:
            with open(filepath, 'wb') as f:
                for chunk in res.iter_content(chunk_size=8192):
                    f.write(chunk)
        else:
            print(f"Failed (Status {res.status_code}): {url}")
    except Exception as e:
        print(f"Error: {e}")
        
    time.sleep(1.5)

print("\nStarting media download for the first 5 posts (Test Mode)...")

# We loop directly over the all_posts list we just scraped!
# (Remove the '[:5]' later if you want to download all 1,000+ posts)
for post in all_posts[:5]:
    if post.get("file") and post["file"].get("path"):
        main_url = f"https://coomer.st{post['file']['path']}"
        download_file(main_url, download_dir)
        
    for att in post.get("attachments", []):
        if att.get("path"):
            att_url = f"https://coomer.st{att['path']}"
            download_file(att_url, download_dir)

print("\nTest finished! Check the 'alina_media' folder.")
