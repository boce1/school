# calculator za valuti evro, paund, lev, dolar
# calculator gradusi i radijani i obratnoto
# calculator binaren kod v 16
# input mesec i godima, proverqva da v tozi mesec v tazi godina ima ponedelnik 24.
# proveri dali e cel broj inputo, posle koren, dali e polozitelen, exception 
# 

options = {
    "euro-lev": 1.96,
    "pound-lev": 2.27,
    "dolar-lev": 1.88,
    "pound-euro": 1.16,
    "lev-euro": 0.51,
    "dolar-euro": 0.96,
    "pound-dolar": 1.21,
    "lev-dolar": 0.53,
    "euro-dolar": 1.04,
    "lev-pound": 0.44,
    "dolar-pound": 0.83,
    "euro-pound" : 0.86
}

m = float(input())
v = input()
v2 = input()

res = m * options[f"{v}-{v2}"]
print(res)