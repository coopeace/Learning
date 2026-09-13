def swap_case(s):
    swapped_str = s.swapcase()
    return swapped_str

if __name__ == '__main__':
    s = input("Enter a string:")
    result = swap_case(s)
    print(result)
 
