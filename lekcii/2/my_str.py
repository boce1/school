from unittest import result


txt = input("enter text: ").split()
result = [el.upper() if txt.index(el)+1%2 != 0 else el.lower() for el in txt]
print(" ".join(result))