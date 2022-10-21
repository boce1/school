def create_list(el, ll=[]):
    ll.append(el)
    return ll

def create_list1(el, ll=None):
    if ll is None:
        ll = []
    ll.append(el)
    return ll

print(create_list(1))
print(create_list(2))
print(create_list(3))
print()

#def a(n, m):
#    print("lol")
#a(m = 3, n = 2)

print(create_list1(1))
print(create_list1(2))
print(create_list1(3))

# *name argument tuple
# **name argument dictionary