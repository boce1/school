def change_values(n, ls_numbers):
    for i in range(len(ls_numbers)):
        if ls_numbers[i] > n:
            ls_numbers[i] = 0
    return ls_numbers

a = [1,2,5,7,8,5,6,8,9,5,4,3,1,5]
print(a)
change_values(4, a)
print(a)
