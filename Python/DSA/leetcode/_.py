n = -123
m = n if n > 0 else -n
reverse_n = 0
while m!=0:
    reverse_n = (reverse_n*10)+m%10
    m //= 10
print(reverse_n if n > 0 else -reverse_n)
