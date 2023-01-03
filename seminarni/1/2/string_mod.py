s = input()
n = len(s)
print()

for i in range(n // 2 + 1):
    if n % 2 == 0 and i == n // 2:
        print((i - 1) * " " + s[n//2 - 1])
        break
    print(i * " " + s[i:n - i])