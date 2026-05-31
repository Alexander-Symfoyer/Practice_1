y = int(input("Enter a height: "))
for x in range(y):
    space = " " *(y-x-1)
    hashtag = (2*x + 1)
    if x == y // 2:
        print(space + "#"*(hashtag//2) + "♦" + "#"*(hashtag//2) )
    else:
        print(space + "#"*hashtag)


for x in reversed("hello"):
    print(x,end="")

print("                                             ")
print("---------------------------------------------")

base = int(input("Enter a base : "))
num = (input("Enter a number : "))
result = 0
power = 0
for digit in reversed(num):
    if digit not in "0123456789ABCDEF":
        print("Invalid input!!!!")
        break
    if digit == 'A':
        value = 10
    elif digit == 'B':
        value = 11
    elif digit == 'C':
        value = 12
    elif digit == 'D':
        value = 13
    elif digit == 'E':
        value = 14
    elif digit == 'F':
        value = 15
    else :
        value = int(digit)
    if value >= base:
        print("Invalid input!!!!")
        break
    result += value*(base**power)
    power += 1
else:
    print(result)

A = int(input("Enter a number : "))
B = int(input("Enter another number : "))
prime = []
count = 0
for num in range (A,B+1):
    if num < 2:
        continue
    is_prime = True
    for i in range (2,num):
        if num % i == 0:
            is_prime = False
            break
    if is_prime:
        prime = prime + [num]
        count += 1
print("found : ",count)
print(prime)
