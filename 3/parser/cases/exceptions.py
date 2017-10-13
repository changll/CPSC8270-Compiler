from random import randint

# handling an exception
def h2(x, y):
    try:
        result = x / y
    except ZeroDivisionError:
        print "division by zero!"
    else:
        print "result is ", result

def h3(x, y):
    try:
        result = x / y
    except ZeroDivisionError:
        print "division by zero!"
    else:
        print "result is ", result
    finally:
        print "executing finally"

# assert
def h1(Temperature):
    assert Temperature >= 0, "It might snow!"
    return ((Temperature-273)*1.8)+32

# raise
def h4():
    try:
        raise Exception('spam', 'eggs')
    except Exception as inst:
        print type(inst)
        print inst.args        

def h5():
    while (randint(0, 20)%2 == 0):
        try:
            print "even number"
        except Exception as inst:
            print "except clause"
        finally:
            print "executing finally"

