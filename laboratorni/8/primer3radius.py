from math import pi 
while True:
    try:
        n = int(input())
        r = int(input())
        if n > 10 and r > 0:
            break
        print("n be greater than 10 and r must be possitive")
    except ValueError:
        print("Invalid input")

l = list(range(1, n + 1))
if r**2 * pi in l:
    print("in")
else:
    print("out")

