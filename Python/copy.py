a = [[10,20],(40,40),69]
b = a.copy()
c=a

print(f"a : {a}")
print(f"c : {c}")
a[1] = [60,30]
a[0] = 'c'


print(f"a : {a}")
print(f"b : {b}")
print(f"c : {c}")

