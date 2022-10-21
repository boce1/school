from math import pi, sin

EPS = 1e-6

x = float(input("x[deg]="))
xrad = x/180*pi

sinx = 0
an_1, an = 0, xrad
counter = 3

while