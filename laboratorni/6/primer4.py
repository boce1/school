# input mesec i godima, proverqva da v tozi mesec v tazi godina ima ponedelnik 24.

import datetime

d = input("Enter mount.year: ")
l = list(map(int, d.split(".")))
my_date = datetime.datetime(l[1], l[0], 24)

if my_date.strftime("%A") == "Monday":
    print(f"24.{l[0]}.{l[1]} is Monday.")
else:
    print("not Monday")