d = {1: "one",
	2: "two",
	3: "three",
	4: "four",
	5: "five"}

for i, v in d.items():
	print(i,"-->", v)

for el in d:
	print(el)

for k in d.keys():
	print(k)

for el in d.items():
	print(el)
	print(el[0], el[1], end = " ")