m = int(input())
l = list(range(0, m + 1)) # l mozes da definiras kako si oces, mozes ss random
l_out = list()

for i in range(len(l)):
    if l[i] % 5 == 3:
        l_out.append(i)
        
