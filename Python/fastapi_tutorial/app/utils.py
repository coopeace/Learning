import json

my_posts = {}

def load_from_file():
    try:
        with open("posts_test.json","r") as read_data:
            my_posts = json.load(read_data)
    except (FileNotFoundError,json.JSONDecodeError):
        my_posts = {}

def save_posts_to_file():
    with open("posts_test.json","w") as write_data:
        json.dump(my_posts,write_data,indent=2)

