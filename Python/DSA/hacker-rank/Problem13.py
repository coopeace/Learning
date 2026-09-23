if __name__ == "__main__":
    s = input()
    an = False #alphanumeric
    alpha = False #alphabetical
    dig = False #digits
    lo = False #lowercase
    up = False #uppercase
    for char in s:
      print(char)
      if (an==False) and (char.isalnum()):
        an=True
        print("here in alphanumeric")
      if (alpha==False) and (char.isalpha()):
        alpha=True
        print("here in alpha")
      if (dig==False) and (char.isdigit()):
        dig=True
        print("here in dig")
      if (lo==False) and (char.islower()):
        lo=True
        print("here in lo")
      if (up==False) and (char.isupper()):
        up=True 
        print("here in up")
    print(an) 
    print(alpha)
    print(dig)
    print(lo)
    print(up)
