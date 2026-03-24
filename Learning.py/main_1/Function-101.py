def number():
    return 10

print(number())

def say_hello(name):
    return "Hello " + name

print(say_hello("Joker"))

def Addnumber(x,y):
    return x + y

print(Addnumber(13652546,1426346))

def addnumber(x,y):
    print("the sum is",x+y)

def subnumber(x,y):
    print("The sub is",x-y)

def mulnumber(x,y):
    print("The mul is",x*y)

def divnumber(x,y):
    print("The dif is",x/y)

addnumber(6,7)
subnumber(7,6)
mulnumber(9,11)
divnumber(11,9)


def vat(price):
    return price*107/100

print(vat(float(input("price : "))))



