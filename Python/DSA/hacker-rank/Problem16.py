#           12 1 | 1 12
#       9 1 | 1 1 | 1 1 | 1 9
#   6 1 | 1 1 | 1 1 | 1 1 | 1 6
# 3 1 | 1 1 | 1 1 | 1 1 | 1 1 | 1 3

# 3 4 2
n,m = map(int,input().split())
k = n//2
t = (m - 7)//2 

for i in range(k):
    print("-"*(k-i)*3+".|."*(2*i+1)+"-"*(k-i)*3)

print("-"*t+"WELCOME"+"-"*t)

for i in range(k-1,-1,-1):
    print("-"*(k-i)*3+".|."*(2*i+1)+"-"*(k-i)*3)
