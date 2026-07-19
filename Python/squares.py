n = int(input("Enter a number:"))

numbers = list(range(1,n+1))

squares = [i**2 for i in numbers]

odd_squares = [i**2 for i in numbers if i%2!=0]

even_squares = [i**2 for i in numbers if i%2==0]

print(numbers)
print(squares)
print(odd_squares)
print(even_squares)
