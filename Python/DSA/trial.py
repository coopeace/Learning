original = [[34,56],[99,101],[21,78]]

shallow = original.copy()

shallow[1].append(999)

print("copy")

print("original")
for _ in original:
    print(_)

