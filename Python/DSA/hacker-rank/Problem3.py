if __name__ == '__main__':
    n = int(input())
    list = []
    for i in range(n):
        user_command,*line = input().split()
        match user_command:
            case "insert":
                list.insert(int(line[0]),int(line[1]))
            case "append":
                list.append(int(line[0]))
            case "print":
                print(list)
            case "remove":
                list.remove(int(line[0]))
            case "sort":
                list.sort()
            case "pop":
                list.pop(-1)
            case "reverse":
                list.reverse()



