fun = lambda a, b: a + b
def foo(n):
    """documentation"""
    return lambda x: x + n

f = foo(5)
print(f(4)) # 5 + 4
print(fun(2,4))
print(foo.__doc__)
print(foo.__annotations__)