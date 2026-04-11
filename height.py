while True:
    try:
        n = int(input("Height(positive integer): "))
        if n<0 :
           print("Enter a positive integer")
        else :
           break
    except ValueError:
        print("Height: _____ <- Enter an integer")

for i in range(n):
    print(f"{i+1}.    #")
