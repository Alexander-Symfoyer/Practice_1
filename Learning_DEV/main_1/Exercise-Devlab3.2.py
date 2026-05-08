a = int(input("Enter any number : "))
if a / 2 == 0:
    print("Evan")
else:
    print("Odd")


a = int(input("Enter any number : "))
if a > 0 :
    print("++Positive++")
elif a < 0 :
    print("--Negative--")
else:
    print("00 Zero 00")

A = int(input("Enter your score : "))
if 100 >= A >= 80 :
    print("Your grade is: A")
elif 79 >= A >= 70 :
    print("Your grade is: B")
elif 69 >= A >= 60 :
    print("Your grade is: C")
elif 59 >= A >= 50 :
    print("Your grade is: D")
elif 49 >= A >= 0 :
    print("Your grade is: F")
else :
    print("Invalid score")


A = str(input("Enter your name : "))
B = str(input("Enter your friend's name : "))
C = str(input("Choose first or last : "))

if C == "first":
    print(A)
elif C == "last":
    print(B)
else:
    print("Invalid choice")


A = str(input("Enter a item : "))
B = str(input("Enter another item : "))

if A < B :
    print("You got",A)
else : 
    print("You got",B)
first = A
Second = B
print("Do you want another item?")
C = str(input("Answer pay! or enough : "))
if C == "pay!" :
    print("You got", first, "and", Second)
elif C == "enough" :
    print("You got", first)
else :
    print("ERROR")










