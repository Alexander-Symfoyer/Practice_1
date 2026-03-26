def login():
    A = str(input("Username : "))
    B = int(input("Password : "))
    if A == "Admin" and B == 1234 :
        return True
    else:
        return False

def menu():
    print("Done!")
    print("-------Ishop!-------")
    print("1. Vat Calculator")
    print("2. Price calculator")

def select():
    D = int(input(">>"))
    return D

def vat():
    price = int(input("Price : "))
    vat = int(input("Vat : "))
    result = price*(100+vat)/100
    print("Total : ",result)

def price():
    price3 = int(input("First price : "))
    price4 = int(input("Second price : "))
    print ("Total : ",price3+price4)

def error():
    print("Invalid input!")



if login():
    menu()
    D = select()
    if D == 1:
        vat()
    elif D == 2:
        price()
    else:
        error()
else:
    error()