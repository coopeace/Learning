# z,y = map(int,input("Enter two numbers:").split())
# print(z*y)

cmd,*args = input("Enter command with values separated by space:").split()
x,y = map(int,args)
print(cmd,type(cmd))
print(x*y)
