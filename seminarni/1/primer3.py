a = int(input())

def piramida(n):
    for i in range(n):
        for j in range(i + 1):
            print("*", end = " ")
        print()
    for i in range(n, 0, -1):
        for j in range(i - 1):
            print("*", end = " ")
        print()

def piramida2(n):
    for i in range(n):
        print((i + 1) * "* ")
    for i in range(n, 0, -1):
        print((i - 1) * "* ")

piramida(a)