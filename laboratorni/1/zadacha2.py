def area(side1, side2, h):
    return (side1 + side2) / 2 * h

a = int(input("Enter the side a: "))
b = int(input("Enter the side b: "))
h = int(input("Enter the height: "))

l = area(a, b, h)
print(f"The surface area is: {l}")
even = "The number is even." if l % 2 == 0 else "The number is odd."
print(even)