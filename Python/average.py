n = int(input())
student_marks = {}
for _ in range(n):
    name, *line = input().split()
    scores = list(map(float, line))
    student_marks[name] = scores
query_name = input()

#student_marks = {Krishna : [67,68,69]}
scores = student_marks[query_name]

average = sum(scores)/len(scores)

print(f"{average:.2f}")
