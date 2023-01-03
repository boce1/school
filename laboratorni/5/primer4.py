# namira vsicki godina mezdu 3000 - 4150 v koito 25.12. e nedelja
import datetime
l = list()
for i in range(3000, 4151):
    d = datetime.datetime(i, 12, 25)
    if d.strftime("%A") == "Sunday":
        l.append(d.year)
print(l)