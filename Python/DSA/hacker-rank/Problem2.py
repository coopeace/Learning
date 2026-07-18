n = 3
student_marks = {}

for _ in range(n):
    name,*line = input("enter name and scores:").split()
    scores = list(map(float,line))
    student_marks[name]= scores
query_name = input("search:")
scores= student_marks[query_name]
average = 0
for _ in scores:
    average+=_
average = "{:.2f}".format(average/len(scores))
print(average)
