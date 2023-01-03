def add(a, b):
    return a + b

def subract(a, b):
    return a - b

def multiply(a, b):
    return a * b

def devision(a, b):
    return a / b

n = int(input())
m = int(input())
operation = input()

if operation == "+":
    print(add(n, m))
elif operation == "-":
    print(subract(n, m))
elif operation == "*":
    print(multiply(n, m))
elif operation == "/":
    print(devision(n, m))
else:
    print("Invalid operator")