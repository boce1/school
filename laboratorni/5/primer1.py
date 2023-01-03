# data ot input -- koj den ot sedmica e

# data ot input -- koja sedmica e

# godina ot klaviaturata -- visikosna li e ili ne e

# namira vsicki godina mezdu 3000 - 4150 v koito 25.12. e nedelja

# spisak na bazata na cjalo 3freno cislo m, elementite sa cisla ot 2 do m prez 3
# posle pogolemi ot 18 kde e 2. cifra cetno cislo

# namira najbliskija palidrnom do navedenata duma

import datetime

d = input("Enter day.mount.year: ")
l = list(map(int, d.split(".")))
my_date = datetime.datetime(l[2],l[1],l[0])

print(my_date.strftime("%A"))