# spisak na bazata na cjalo 3freno cislo m, elementite sa cisla ot 2 do m prez 3
# posle pogolemi ot 18 kde e 2. cifra cetno cislo

m = int(input())
l = list()
l2 = list()

for i in range(2, m + 1, 3):
    l.append(i)

for el in l:
    temp = str(el)
    if el > 18 and len(temp) > 1 and int(temp[1]) % 2 == 0:
        l2.append(el)

print(l)
print(l2)