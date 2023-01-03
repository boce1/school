def calculate(a, b, operati_sign):
    if operati_sign == "+":
        return a + b
    elif operati_sign == "-":
        return a - b
    elif operati_sign == "*":
        return a * b
    elif operati_sign == "/":
        return a // b
    else:
        return "Invalid sign" 

n1 = int(input("Enter the first number: "))
n2 = int(input("Enter the second number: "))
sign = input("Enter the sign of operation(+,-,*,/): ")

print(calculate(n1, n2, sign))