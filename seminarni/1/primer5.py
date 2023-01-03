n = int(input("Enter the number: "))
ls = []

print()
for i in range(n):
    ls.append(int(input()))
print("The greatest number is", max(ls))