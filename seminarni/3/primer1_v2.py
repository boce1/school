def check_valid_email(email):
    l = email.split("@")
    l = email.split(".")
    return len(l) == 3

my_email = "zarev.bojan2@gmail.com"
my_e = "sdfsdf.com"
print(check_valid_email(my_email))
print(check_valid_email(my_e))