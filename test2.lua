dofile"tm.lua"

a=Bnumber"0.2"
print(a)
b=Bnumber"0.03"
print(b)
print(a*b)
Bdigits(30)
a=Bnumber"1"
print(a/23)

Bdigits(70)
a=4*Batan(1)
print(a)
Bdigits(19)
print(Bround(a))

Bdigits(70)
pi=4*Batan(1)
function Brad(x) return pi/180*x end
a=Brad(30)
print(a) print(pi/6)
s,c=Bsincos(a)
print(s,c,s^2+c^2)
s,c=Bsin(a),Bcos(a)
print((2*c)^2)
print(c)
print(Bsqrt(3)/2)
