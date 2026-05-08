A = int(input("Enter a number: "))
B = int(input("Enter a number: "))
C = int(input("Increase or Decrease by: "))
if C <=0 :
    print("C must be greater than 0")
elif A > B:
    for x in range(A, B - 1,-C):
        print(x,end=" ")
elif A < B:
    for x in range(A,B + 1,+C):
        print(x,end=" ")

y = int(input("Enter a height: "))
for x in range(y):
    print("="*(x+1))





