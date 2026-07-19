from typing import List

Tasks = []

Menu = ["Add a Task","Modify Task","Remove Task","View Tasks","Empty Database","Quit"]

def print_list(List : List[str]) -> None:
    for i,j in enumerate(List):
        print(f"{i+1}. {j}")

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
            modify_index = int(input("Which index task do you want to modify: "))
            old_task = Tasks.pop(modify_index - 1)
            print(f"Before: {old_task}")
            new_task = input(f"Edit  : ")
            Tasks.insert(modify_index-1,new_task)
            print("Task Modified\n")
        case 3:
            remove_index = int(input("Which index task do you want to modify: "))
            Tasks.pop(remove_index - 1)
            print("Task Removed.\n")
        case 4:
            if (len(Tasks)==0):
                print("No Task in Manager\n")
                continue
            print("---------------------------------------------------------------------")
            print("                               Tasks")
            print("---------------------------------------------------------------------")
            print_list(Tasks)
            print("---------------------------------------------------------------------\n")
        case 5:
            if (input("Are you sure about emptying Tasks(y for yes): ").upper()=='Y'):
                Tasks = []
                print("Tasks Emptied\n")
            else : 
                print("Returning to main menu\n")
        case 6:
            break
        case _:
            print("Please Enter a valid Choice:\n")
