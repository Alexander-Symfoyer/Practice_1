
A = int(input("Any number : "))
B = int(input("Any number :"))
C = A > B
print("Is A greater than B?", C)

A = int(input("Enter your password :"))
B = int(input("Enter your password again :"))
C = A==B
print("Is the password correct?", C)

x = int(input("Give me a number :"))
y = int(input("Give me another number :"))
X = x + y
Y = x - y
print("Is the sum greater than the difference?",X>Y)

A = int(input("Enter a price :"))
B = int(input("Enter a down payment :"))
C = int(input("Enter a monthly payment :"))
D = (A-B)/C
print("It will take", D, "months to pay off the loan.")

x = str(input("Enter a Name :"))
y = str(input("Enter a Surname :"))
z = x + " " + y
A = int(input("Date of birth : "))
B = int(input("Month of birth :"))
C = int(input("Year of birth :"))
D = str(A) +"/"+ str(B) +"/" + str(C)
print("Hi!, My name is", z)
print("My birthday is", D)
print("You can call me", x)


