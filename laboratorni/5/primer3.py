def is_leap(y):
    return year % 400 == 0 or y % 100 != 0 and y % 4 == 0

year = int(input())

if is_leap(year):
    print(f"{year} is leap year")
else:
    print(f"{year} is NOT leap year")

