a = int(input())

d = dict()
for i in range(a):
    d[i + 1] = a - i

print(d)