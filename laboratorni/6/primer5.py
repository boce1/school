from math import sqrt
while True:
    try:
        n = int(input())
        if n == 0:
            print("Number must be greater than 0!")
            continue
        print(F'Square root of {n} is {sqrt(n)}')
        break
    except ValueError:
        print("Invalid input!\nNumber must be whole and positive!")
    
