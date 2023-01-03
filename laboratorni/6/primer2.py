from math import pi
n = int(input("Enter the number you want to transform: "))
unit = input("Enter the unit you want to convert to (degrees/radians): ")

if unit == "radians":
    n = n * pi / 180
    print(n)
elif unit == "degrees":
    n = n * 180 / pi
    print(n)
else:
    print("Invalid input.")