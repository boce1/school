arr = list(range(1, 10, 2))
n = len(arr)

for i in range(n):
    print((n - i - 1) * " ", end="")
    print(arr[i] * "!")

print()

#for i in range(n):
#    print((n - i - 1) * " ", end="")
#    print(arr[n - i - 1] * "!")
