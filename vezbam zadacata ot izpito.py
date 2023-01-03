while True:
	try:
		n = int(input())
		k = int(input())
		break
	except ValueError:
		print("Invalid input")
print()

ls = list()
while True:
	try:
		for i in range(n):
			ls.append(int(input()))
		break
	except ValueError:
		print("Invalid input")

ls1 = [x for x in ls if x > k]

product = 1
is_there_number = False
for i in range(len(ls1)):
	if i % 2 != 0:
		product *= ls1[i]
		is_there_number = True

if not is_there_number:
	product = None

if len(ls1) > 0:
	min_value_index = ls1.index(min(ls1))
else:
	min_value_index = None


ls2 = [x for x in ls if x <= k if x > 0]
res = max(ls2) - min(ls2)

print(f"ls1: {ls1}\nls2: {ls2}")
print(f"part1: product: {product}; index of the min value: {min_value_index}")
print(f"part2: razlika: {res}")