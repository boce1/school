from math import pi

def factorial(n):
    if n == 1:
        return n
    return n * factorial(n - 1)

def aproximate_sin(degrees, n):
    # x - (1/3! * x**3) + (1/5! * x**5) - (1/7! * x**7) + ...
    radians = degrees / 180 * pi
    result = 0
    for i in range(n):
        num = i * 2 + 1
        result += (-1)**i * radians**num / factorial(num)
    return result

while True:
    try:
        degrees = int(input("Enter degrees: "))
        aproximation = int(input("Enter number that describes aproximation: "))
        break
    except ValueError:
        print()
        print("Input must be numbers.")
        continue
print(aproximate_sin(degrees, aproximation))