inp = input("Enter the text: ")

dict = {}
for x in inp:
    if x not in dict:
        dict[x] = 1
    else:
        dict[x] += 1

print(dict)