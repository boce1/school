from unittest import result


def fib(n = 5): 
    result = []
    a, b = 0, 1
    for _ in range(n):
        result.append(b)
        a, b = b, a + b
    return result

print(fib())

# a = (1,23,2) - kortej e unmutable
# raise ako se generira error

