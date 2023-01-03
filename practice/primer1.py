def foo(a, b, c):
    print(a + b + c)

def fun(*args):
    for i in args:
        print(i, end = ' ')
    print()

def func(a = "aloooo", *args, **kwargs): # a = ovdeka nema nikakva poenta deka zima zima u sek slucaj
    print(a)
    for i in args:
        print(i, end = "#")
    print()
    for x in kwargs:
        print(x, kwargs[x])
    print()

#foo(c = 5, a = 4, b = 6)
#foo(5, c = 4, b = 6)
#fun(1,2,3,4,5,6,7,8)
#func("aloo", 1,2,3,4, q = "b", w = "o")

d = {1:"b",
2: "o",
3: "k",
4: "i"}

#for i in range(len(d)):
#    print(d[i + 1], end = "")

def a(*args):
    print(len(args) * "{} ".format(*args))

def b(*args):
    print(len(args) * "{}#".format(*args))
def c(**kwargs):
    print(kwargs)
#b([1,2,3])
c(a=2,b=3,c=4)

