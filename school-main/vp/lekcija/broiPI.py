# gitbug/dgotseva
# github Desktop
import math
# ako e istoto moeto i na blibliotekata intrepretero koristi moite variabli

EPS = 1e-6 # aposilutna greshka
pi = 0
sign = -1
counter = 3
an_1 = 0
an = 1

while abs(an - an_1) >= EPS:
    pi += an
    an_1, an = an, sign/counter
    sign *= -1
    counter += 2

pi *= 4
print('pi={0}/nPi={1}'.format(pi, math.pi))