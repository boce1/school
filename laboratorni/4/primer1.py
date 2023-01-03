# 1 generira kombinacija na string x y z o
# 2 razpoznava da li e monotono namaljavasta ili narastvasta
# spisak, funkcija # ako ne e ni edno ne moz se opredeli
# 3 prebrojava golemite i malkite bukvi i gi pise u recnik
# lowers : brojo na malenkite uppers : brojo na golemite
# 4 funckija ss sipsak od 20 cisla povtarjasti
# dava nov spisak kde samo s nepovtarjastite

import random
i = ["x", "y", "z", "o"]
li = []
n = 0

while n < 24:
    random.shuffle(i)
    a = "".join(i)
    if a not in li:
        li.append(a)
        n += 1
print(li)
print(len(li))