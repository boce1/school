def rev_sentence(s):
    s = [f"{x} " for x in reversed(s.split())]
    return "".join(s)

def rev_sen2(s):
    n = len(s)
    out = ""
    word = ""
    for i in range(n):
        word += s[i]
        if i == n - 1 and s[i] != " ":
            word += " "
        if s[i] == " " or i == n - 1:
            out = word + out
            word = ""
    return out

def rev_sen3(s):
    out = ""
    k = 0
    n = len(s)
    for i in range(n):
        if s[i] == " ":
            out = s[k : i] + " " + out
            k = i + 1
        elif i == n - 1:
            out = s[k:] + " " + out
    return out


a = "i love to go to school"
print(rev_sen3(a))