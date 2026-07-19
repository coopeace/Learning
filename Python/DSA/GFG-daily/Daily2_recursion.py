# Last attempt at n increasing digit question

n = int(input("Enter a number:"))
pool = "123456789"
res = []

def adder(t:int) -> int:
    if t==0:
        return 0
    return (10**(t-1))+adder(t-1)

def recursion(num,n,t):
    if n<1:
        return
    add = adder(t)
    num+=add
    res.append(num)
    recursion(num,n-1,t)

i_num = int(pool[:n])
res.append(i_num)
k=n
recursion(i_num,9-n,k)
copy = res[::]
for i in range(len(copy)):
    recursion(copy[i],9-n-i,k-1)
for i in range(len(copy)):
    recursion(copy[i],9-n-i,k-2)

res.sort()
print(res)
