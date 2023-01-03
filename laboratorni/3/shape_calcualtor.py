from math import pi

def circle_area(r):
    return r**2 * pi

def square_area(a, b):
    return a * b

def triangle_area(a, h):
    return square_area(a, h) / 2


def main(shape):
    if shape == "circle":
        radius = int(input())
        print(circle_area(radius))
    elif shape == "rect":
        n = int(input())
        m = int(input())
        print(square_area(n, m))
    elif shape == "triangle":
        n = int(input())
        h = int(input())
        print(triangle_area(n, h))    
    else:
        print("invalid shape")


shape = input("Enter the shape you want to calculate: (circle, rect, parallogram, triangle)")
main(shape)