s = set([1,2,3,4])

#print(type(s), s)
#s.add(44)
#s.add(11)
#s.remove(2)
#print(s)
#s.update({3, 4, 55, -11}) # odedinenie
#print(s)
#
#s |= {1, 2, 7}
#print(s)
#s &= {1, 2, 3, 4, 5}
#print(s)

us = frozenset([1, 2, 3, 4, 5])
print(type(us), us)

# frozenset se ne moze promeni
# frozenset nema update add ili remove
# no
us |= {1, 2, 7}
print(us)
us &= {1, 2, 3, 4, 5}
print(us)
