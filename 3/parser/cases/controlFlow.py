# if, elif, else
def f1():
	x = 42
	if x < 0:
		x = 0
		print 'Negative changed to zero'
	elif x == 0:
		print 'Zero'
	elif x == 1:
		print 'Single'
	else:
		print 'More'

# for, if, list
def f2():
	words = ['cat', 'window', 'door']
	for w in words:
		if len(w) > 5:
			print w

# break, continue, and else on loops
def f3():
	for n in range(2, 20):
		for x in (2, n):
			if n % x == 0:
				print n, ' equals ', x, ' * ', n/x
				break
			else:
				print n, ' is a prime number'

f1()
f2()
