x = int(input("Enter a digit: "))
total = 0
while x > 0:
    total += x % 10
    x = x // 10
print("Sum of digits:", total)

y = int(input("Enter a height: "))
for x in range(y // 2 + 1):
    space = " " *(y // 2 - x)
    star = "*" *(2*x + 1)
    print(space + star)
for x in range(y // 2):
    space = " " *(x + 1)
    star = "*" *(y - 2*(x+1))
    print(space + star)

A = int(input("Enter a height: "))
for x in range(A//2+1):
    B = " " *(A//2-x)
    C = "*" *(2*x+1)
    print(B+C)
for x in range(A//2):
    B = " "*(x+1)
    C = "*"*(A-2*(x+1))
    print(B+C)