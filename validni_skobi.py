def valid_brackets(s):
    opposites = {
        "(" : ")",
        "[" : "]", 
        "{" : "}"
    }

    s = s.split()
    s = [l for l in "".join(s)]
    index = 1
    n = len(s)
    while n > 0:
        first_chr = s[0]
        if (index >= n) or (not first_chr in ("(", "[", "{")):
            return False
        if s[index] != opposites[first_chr]:
            index += 1
        else:
            s.pop(index)
            s.pop(0)
            index = 1
            n = len(s)
    return True

t1 = "((){)}"
print(valid_brackets(t1))
