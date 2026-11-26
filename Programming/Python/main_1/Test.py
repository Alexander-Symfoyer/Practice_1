A = str(input("Username : "))
B = int(input("Password : "))
if A == "Admin" and B == 1234 :
    print("Done!")
    print("-------Ishop!-------")
    print("1. Vat Calculator")
    print("2. Price calculator")
    C = int(input(">>"))
    if C == 1:
        price = float(input("Price : "))
        result = price*107/100
        print("Total is",result)
    elif C == 2:
        price1 = int(input("First price : "))
        price2 = int(input("Second price : "))
        print("Total is ",price1+price2)
    else:
        print("Invalid number!")
        print("Try again")
elif A != "Admin" or B == 1234 :
    print("Invalid Username!")
elif A == "Admin" or B != 1234 :
    print("Invalid password!")
else :
    print("Invalid Username or Password!")










