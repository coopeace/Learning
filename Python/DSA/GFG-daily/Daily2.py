# Digit Question
# Input: n = 1
# Output: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
# False was being overwritten

n = int(input("Enter a number:"))
res = []
base=10**(n-1)
j=10**n
def follow_contraits(s,n):
    if n<2:
        return True
    elif follow_contraits(s,n-1) == False:
        return False
    elif s[n-1] > s[n-2]:
        return True
    else:
        return False

    
if base==1:
    for k in range(0,j):
        res.append(k)
else:
    for k in range(base,j):
        s = str(k)
        if follow_contraits(s,n):  
            res.append(k)

print(res)
