from random import randint

n = int(input("Enter the lenght of array: "))

l = []
for i in range(n):
    l.append(randint(0, 100))

s = sum(l)

temp = False
dev = (2, 3, 5, 7)
for i in dev:
    if s % i == 0:
        temp = True
        break

print(f"sum is {s},  list is {l}")
if temp:
    print("The number is NOT prime number")
else:
    print("The number is prime number")

# if s % 2 == 0 or s % 3 == 0 or s % 5 == 0 or s % 7 == 0 the number is not prime
# if s % 2 != 0 and s % 3 != 0 and s % 5 != 0 and s % 7 != 0 the number is not prime