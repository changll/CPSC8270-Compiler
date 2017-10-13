# yield is best used when you have a function that returns a sequence and you want to iterate over that sequence, 
# but you do not need to have every value in memory at once.

# create generators
def g2():
    mylist = range(10)
    for i in mylist:
        yield i*i

# get lines
def g1(files):
    for f in files:
        for line in f:
            #preprocess line
            yield line

g1([[1, 2, 3], [4, 5, 6]])
g2()
