shows = ["The Big Bang Theory","Friends","Game of Thrones","Parks and Recreations"]
sports = ["Cricket","Hockey","Football","Badminton"]
for sport,show in zip(sports,shows):
    print(f'''
    sport:{sport}
    show:{show}''')
