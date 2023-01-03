from math import pi

while True:
    try:
        n = int(input()) 
        if not 1000 <= n <= 2000:
            print("n must be between 1000 and 2000")
        else:
            break
    except:
        print("Invalid input")

if "7" in str(n / pi)[3:8]:
    print("There is 5")
else:
    print("There is no 5")