def make_chr_list(from_num, to_num):
    return [chr(x) for x in range(from_num, to_num + 1)] # [a, b], not [a, b)

def convert(number, base):
    numbers = [str(x) for x in range(10)] + make_chr_list(65, 90) + make_chr_list(97, 122)
    result = ''
    while number != 0:
        result += numbers[number % base]
        number //= base
    return result[::-1]

def convert2(number, base):
    numbers = [str(x) for x in range(10)] + make_chr_list(65, 90) + make_chr_list(97, 122)
    result = ''
    while number != 0:
        result = numbers[number % base] + result
        number //= base
    return result

print(convert2(25, 16))