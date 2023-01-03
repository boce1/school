num = input()
digits = list(map(str, list(range(10)))) + ["A", "B", "C", "D", "E", "F"]

res = 0
len_num = len(num)
for i in range(len_num):
    res += int(num[i]) * 2 ** (len_num - (i + 1))

res_hexadecimal = ""
while res > 0:
    digit = res % 16
    res_hexadecimal += digits[digit]
    res //= 16

res_hexadecimal = res_hexadecimal[::-1]
print(res_hexadecimal)