numbers = input().split()
print(numbers)

even = [int(el) for el in numbers if sum(map(int, el))%2 == 0]
# map(funkcija , broj)
print(even)
print(sum(even))


# -----------------
n = int(input("n = "))
numbers = []
for _ in range(n):
    x = int(input())
    numbers.append()

s = 0
for el in numbers:
    sum_digit = 0
    x = el
    while x > 0:
        sum_digit += x % 10
        x //= 10

    if sum_digit % 2 == 0:
        sum += el