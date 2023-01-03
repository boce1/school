inp = input("Enter your string: ")

d = dict()

lowers = len([x for x in inp if x.islower()])
uppers = len([x for x in inp if x.isupper()])

d  ["lowers"] = lowers
d["uppers"] = uppers
print(d)
