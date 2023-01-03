def check_valid_email(email):
    n = len(email)
    valid_at = False
    valid_dot = False
    valid_domain = False
    for i in range(n):
        current_chr = email[i]
        prev_chr = email[i - 1]
        if current_chr == "@" and (prev_chr.isalpha() or prev_chr.isnumeric()):
            valid_at = True
        if current_chr == "." and (prev_chr.isalpha() or prev_chr.isnumeric()):
            valid_dot = True
    if email[n - 4:] == ".com":
        valid_domain = True
    return valid_at and valid_dot and valid_domain

my_e = "zarev.bojan2@gmail.com"
my_e2 = "asdasd.com"
my_e3 = "sjdfhksdhfkj.@"
my_e4 = "sjdfhksdh@fkj"

print(check_valid_email(my_e))
print(check_valid_email(my_e2))
print(check_valid_email(my_e3))
print(check_valid_email(my_e4))
        