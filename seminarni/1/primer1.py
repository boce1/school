def find_ls(n):
    l = list()
    for i in range(n + 1):
        if i % 6 == 0 and i % 8 == 0:
            l.append(i)
    return l

def find_ls2(n):
    return [x for x in range(n + 1) if x % 6 == 0 if x % 8 == 0]

for i in range(5001):
    if i % 6 == 0 and i % 8 == 0:
        print(i)

#print(find_ls(5000))
#print(find_ls(5000) == find_ls2(5000))