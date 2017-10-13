from random import randint

def c2():
    dishes = {'eggs': 2, 'sausage': 1, 'bacon': 1, 'spam': 500}
    keys = dishes.viewkeys()
    vals = dishes.viewvalues()
    print list(keys)
    print list(vals)

def c1():
    lists = [[] for i in range(5)]
    for list in lists:
        list.append(randint(0, 100))
    print lists

c1()
c2()
