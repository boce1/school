a = [8, 3, 11, 24, 13]
b = sorted(a)
if a == b:
    print("Incrised")
elif a == reversed(b):
    print("DEcreased")
else:
    print("Undefined")
