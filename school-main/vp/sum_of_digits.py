def sum_digits(number):
    suma = 0
    while number != 0:
        suma += number % 10
        number //= 10
    return suma

def find_even_sum(lst):
    return [x for x in lst if sum_digits(x) % 2 == 0]

print(find_even_sum([12,12,76,1,23,2,12,3,76,43534,5,346,54,6,45,6,345,7,34,5]))
#print(sum_digits(5504320))