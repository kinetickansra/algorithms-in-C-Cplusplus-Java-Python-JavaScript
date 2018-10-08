def karatsuba(x,y):
	if len(str(x)) or len(str(y)) :
		return x*y
	else:
		n = max(len(str(x)),len(str(y)))
		z = n / 2
		a = x / 10**(z)
		b = x % 10**(z)
		c = y / 10**(z)
		d = y % 10**(z)
		ac = karatsuba(a,c)
		bd = karatsuba(b,d)
		adbc = karatsuba(a+b,c+d) - ac - bd
		return ac * 10**(2*z) + (adbc * 10**z) + bd

karatsuba (923,1723)