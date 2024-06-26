import sympy
from sympy.abc import x, y

def func(x, y):
    return sympy.exp(x) + y**3

z = func(x, y)
print('z =', z)

dz_dx = z.diff(x)
print('dz_dx =', dz_dx)

dz_dy = z.diff(y)
print('dz_dy =', dz_dy)
print(dz_dy.evalf(subs={y: 1}))
