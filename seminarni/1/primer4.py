arr = list(map(int, input("Enter three numbers: ").split()))

def chech_triangle(arr):
    if arr[0] + arr[1] > arr[2]:
        print("Sides can make triangle")

        arr = sorted(arr)
        a, b, c = zip(arr)
        if a == b == c:
            print("Triangle is equilateral")
        elif a == c or a == b or b == c:
            print("Triangle is isosceles")
        else:
            print("Triangle is scalane triangle")
    else:
        print("That's not triangle")

chech_triangle(arr)