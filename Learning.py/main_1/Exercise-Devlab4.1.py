A = int(input("Enter a number: "))
for x in range(A):
    print(x+1,end=" ")

A = int(input("Enter a number: "))
B = int(input("Enter a number: "))
if A > B:
    for x in range(B, A + 1):
        print(A+1-x,end=" ")
if A < B:
    for x in range(A,B + 1):
        print(x,end=" ")
else:
    print("Try again")




