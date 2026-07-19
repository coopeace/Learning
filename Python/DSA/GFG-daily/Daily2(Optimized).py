# Digit Question(Optimized)

n = int(input("Enter a number:"))
pool = "123456789"
res = []
def copy_elements(copy,n):
    if n<0:
            return
    copy_elements(copy,n-1)
    copy.pop(0)
    lenofcopy = len(copy)
    for i in range(lenofcopy):
        copy[i]+=10
        res.append(copy[i])
    print(copy)
    return

if n==1:
    for k in range(0,10):
        res.append(k)
else:
    splice = pool[:n-1]
    num = int(splice)
    num *= 10
    for j in range(n-1,9):
        res.append(num+int(pool[j]))
copy=res[::]
copy_elements(copy,len(copy)-2)    
res.sort()
print(res)
