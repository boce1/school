inp = input("Enter the string that represent keywords: ")
chars = list(set(inp))

dict = {}
for i in range(len(chars)):
    c = chars[i]
    dict[c] = inp.count(c)

print(dict)
