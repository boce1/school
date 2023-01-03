while True:
    try:
        n = int(input())
        k = int(input())
        if n > 0:
            break
        print("n must be greater than 0")
    except ValueError:
        print("Invalid input")

l = list()
for i in range(n):
    while True:
        try:
            l.append(int(input()))
            break
        except ValueError:
            print("Invalid input")

# # #
l1 = [x for x in l if x > k]

product = 1
for i in range(n):
    if i % 2 == 1:
        product *= l1[i]


min_l1 = l1.index(min(l1))
# # #

l2 = [x for x in l if x <= k if x > 0]
razlika = max(l2) - min(l2)
