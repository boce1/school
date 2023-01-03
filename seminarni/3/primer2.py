def longest_word(s):
    s = s.split()
    l_w = s[0]
    for word in s:
        if len(word) > len(l_w):
            l_w = word
    return l_w

def shortest_word(s):
    s = s.split()
    s_w = s[0]
    for word in s:
        if len(word) < len(s_w):
            s_w = word
    return s_w

my_s = input()
print(longest_word(my_s))
print(shortest_word(my_s))
