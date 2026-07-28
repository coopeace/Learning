from typing import List
import json
from datetime import datetime

Tasks = []

content = {
        "tasks" : [],
        "last_updated": ""
        }

Menu = ["Add a Task","Modify Task","Remove Task","View Tasks","Empty Database","Save and Quit","Show me Completed Tasks"]

try:
    with open("task.json","r") as sourceFile:
        content = json.load(sourceFile)
        Tasks = content["tasks"]
except FileNotFoundError as e:
    print("Error:",e)

def print_list(List : List[str]) -> None:
    for i,j in enumerate(List):
        print(f"{i+1}. {j}")

def print_tasks(Tasks : List[str]) -> None:
    if (len(Tasks)==0):
        print("No Task in Manager\n")
    else :
        print("---------------------------------------------------------------------")
        print("                               Tasks")
        print("---------------------------------------------------------------------")
        print_list(Tasks)
        print("---------------------------------------------------------------------\n")

while (True):
    print_list(Menu)

    n = int(input("Choice: "))
    print("")
    match n:
        case 1:
            task = input("> ")
            Tasks.append(task)
            print("Task added.\n")
        case 2:
            print_tasks(Tasks)
            modify_index = int(input("Which index task do you want to modify: "))
            old_task = Tasks.pop(modify_index - 1)
            print(f"Before: {old_task}")
            new_task = input(f"Edit  : ")
            Tasks.insert(modify_index-1,new_task)
            print("Task Modified\n")
        case 3:
            print_tasks(Tasks)
            remove_index = int(input("Which index task do you want to remove: "))
            Tasks.pop(remove_index - 1)
            print("Task Removed.\n")
        case 4:
            print_tasks(Tasks)
        case 5:
            if (input("Are you sure about emptying Tasks(y for yes): ").upper()=='Y'):
                Tasks = []
                print("Tasks Emptied\n")
            else : 
                print("Returning to main menu\n")
        case 6:
            current_time = str(datetime.now().replace(microsecond=0))
            content = {
                    "tasks" : Tasks,
                    "last_updated" : current_time
                    }
            try:
                with open("task.json","w") as writeFile:
                    json.dump(content,writeFile,indent=4)
                    print("File is successfully saved..... ")
            except:
                print("File Write was not successful!!")
            break
        case _:
            print("Please Enter a valid Choice:\n")
