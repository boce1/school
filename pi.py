def aproximate_pi(n):
    # 1 - 1/3 + 1/5 - 1/7 + ... = PI / 4
    pi = 0
    for i in range(n):
        devisor = i * 2 + 1
        pi += (-1)**i / devisor
    return pi * 4

presition = 0
while presition < 1:
    print("The number must greater than 0.")
    try:
        presition = int(input("Enter the number wich describes presition of aproximation of PI: "))
    except ValueError:
        print()
        print("Input must be number.")
        continue
print(aproximate_pi(presition))
