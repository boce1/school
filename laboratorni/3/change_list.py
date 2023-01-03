def modify(l, n):
    return [x if x <= n else 0 for x in l]

ls = list(map(int, input("Enter the list and separate the numbers with spaces: ").split()))
a = int(input("Enter the number: "))

print(modify(ls, a))