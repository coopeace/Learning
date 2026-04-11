my_list = []
for _ in range(int(input("Enter number: "))):
    name = input("Enter a name: ").capitalize()
    score = float(input("Enter a score: "))
    my_list.append([name,score])

unique_scores = sorted(set(li[1] for li in my_list))

second_highest_score = unique_scores[1]

students_names = [s[0] for s in my_list if s[1] == second_highest_score ]

students_names.sort()

for name in students_names:
    print(name)
