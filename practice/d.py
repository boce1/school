from re import I


a = dict()
n = int(input())
for i in range(n):
    a[i + 1] = n - i

def foo(q : str = 'i', b: int = 10, /):
    print(q, b)
    print(foo.__annotations__)
    print(type(b))
foo(8, 4)