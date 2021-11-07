

# This file was *autogenerated* from the file solve.sage
from sage.all_cmdline import *   # import sage library

_sage_const_13 = Integer(13); _sage_const_2 = Integer(2); _sage_const_3 = Integer(3); _sage_const_7 = Integer(7); _sage_const_0 = Integer(0)
P = PolynomialRing(ZZ, names=('x',)); (x,) = P._first_ngens(1)
f = _sage_const_13 *x**_sage_const_2  + _sage_const_3 *x + _sage_const_7 

enc = open('../source/out.txt', 'r').read().strip()
flag = ''
for c in enc:
    p = (f - ord(c)).roots()[_sage_const_0 ][_sage_const_0 ]
    flag += chr(p)
print(flag)
