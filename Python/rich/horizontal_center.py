import shutil
from InquirerPy import inquirer
from InquirerPy.base.control import Choice

# 1. Define your options
options = ["Start Application", "Settings & Preferences", "Check Updates", "Exit"]
message_text = "Select an Option"

# 2. Get terminal width
term_width = shutil.get_terminal_size().columns

# InquirerPy adds ~3 characters for the pointer icon ("> ") and cursor space
POINTER_WIDTH = 2

# 3. Find the widest item to ensure uniform left alignment while centered
max_item_len = max(len(opt) for opt in options)
total_menu_width = max_item_len + POINTER_WIDTH

# 4. Calculate left margin spaces
menu_left_pad = max(0, (term_width - total_menu_width) // 2)
message_left_pad = max(0, (term_width - len(message_text) - 2) // 2)

# 5. Build centered choices
choices = [
    Choice(
        name=f"{' ' * menu_left_pad}{opt}",
        value=opt
    )
    for opt in options
]

# 6. Execute prompt
selected = inquirer.select(
    message=f"{' ' * message_left_pad}{message_text}",
    choices=choices,
    pointer="> ",
    qmark="",  # Remove default '?' icon to keep header calculation clean
).execute()

print(f"Selected: {selected}")
