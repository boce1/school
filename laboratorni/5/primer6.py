# namira najbliskija palidrnom do navedenata duma
s = input()
s_temp = "".join(s.split()).lower()

if s_temp[:] == s_temp[::-1]:
    print(f"{s} is pallyndrom")
else:
    n = len(s)//2
    if n % 2 != 0:
        print(f"The closest pallyndrome is: {s[:n] + s[n::-1]}")
    else:
        print(f"The closest pallyndrome is: {s[:n] + s[n - 1::-1]}")

# asd
# asdas -- asdsa

# asdr -- assa

# qweasd -- qweewq
# qweraop -- qwerwwq