def encrypt(s):
    res = ""
    for letter in s:
        if letter != " ":
            ascii_num = ord(letter) + 9
            letter = chr(ascii_num)
        if letter == " " or letter.isalpha():
            res += letter
    return res

def change_case(s):
    res = ""
    for letter in s:
        if letter.islower():
            letter = letter.upper()
        elif letter.isupper():    
            letter = letter.lower()
        res += letter

    return res

my_s = input()
print(encrypt(my_s))
print(change_case(encrypt(my_s)))
