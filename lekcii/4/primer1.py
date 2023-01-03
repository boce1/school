with open("lorem.txt") as f:
    print(f.read())

with open("lorem.txt") as f:
    for line in f:
        print(line) 