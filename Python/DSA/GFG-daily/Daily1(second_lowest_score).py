if __name__ == '__main__':
    records = []
    for _ in range(int(input("Enter number: "))):
        name = input("Enter a name: ").capitalize()
        score = float(input("Enter a score: "))
        records.append([name,score])
    scores = [index[1] for index in records]

    sorted_scores = list(sorted(set(scores)))

    second_lowest_score = sorted_scores[1]

    res = [index[0] for index in records if index[1] == second_lowest_score]

    for name in sorted(res):
        print(name)

