from random import randint

def foo(l):
    return list(set(l))

ls = list()
for i in range(20):
    ls.append(randint(1, 10))

print(ls)
print(foo(ls))