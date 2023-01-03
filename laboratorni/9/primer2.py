def tablica1():
    for i in range(1, 21):
        for j in range(1, 11):
            print(f"{i} * {j} = {i * j}")
        print()

def tablica2():
    for i in range(1, 21):
        print("{:02} {:02} {:02}".format(i - 1, i, 2*i - 1))


#tablica1()
tablica2()  