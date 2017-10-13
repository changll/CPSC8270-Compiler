# bitwise operations
def f1():
	x = 11
	y = 157
	r_and = x & y
	r_or = x | y
	r_xor = x ^ y
	r_not = ~x
	print 'and ', r_and, 'or ',r_or, 'xor ', r_xor, 'not ', r_not
	z = 1024
	r_left = z << 1
	r_right = z >> 1
	print 'left ', r_left, 'right ', r_right

