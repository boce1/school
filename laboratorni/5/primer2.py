import datetime

d = input("Enter day.mount.year: ")
l = list(map(int, d.split(".")))
my_date = datetime.datetime(l[2],l[1],l[0])

print(my_date.strftime("%W"))