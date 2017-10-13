from contextlib import contextmanager

# use try..finally do the same things
def p2():
    try:
        file = open("hello.txt", "r")
        print file.read()
    except IOError:
        print 'An I/O error has occurred!'
    except:
        print 'An unknown error has occurred!'
    finally:
        file.close()

# read a file w/o call close()
def p1():
    with open("hello.txt", "r") as file:
        print file.read()

def call():
    with opening("hello.txt") as file:
        for line in file:
            print line        

@contextmanager
def opening(name):
    file = open(name)
    try:
        yield file
    finally:
        file.close()
