A = float(input("Enter your temperature in Celsius : "))
if A >= 37.5 :
    print("Beep!")
else:
    print("Welcome")

A = str(input("Username : "))
B = int(input("Password : "))
if A == "Knight" and B == 123 :
    print("Lets's GO!!!!!!")
else:
    print("No NO!!")

a = int(input("Any Numbers : "))
b = int(input("Another Numbers : "))
c = int(input("Another Numbers : "))
d = int(input("Another Numbers : "))
e = int(input("Another Numbers : "))

max = a
if b > max :
    max = b
if c > max :
    max = c
if d > max :
    max = d
if e > max :
    max = e

min = a
if b < min :
    min = b
if c < min :
    min = c
if d < min :
    min = d
if e < min :
    min = e

print("Maximum valve : "+ str(max))
print("Minimum valve : " + str(min))











































