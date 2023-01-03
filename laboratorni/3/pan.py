# a - 97
# z - 122

ls = set(map(chr, range(97, 123)))
inp = set(input().lower())

if ls.issubset(inp):
    print("The sentence is pangram")
else:
    print("The sentence is NOT pangram")