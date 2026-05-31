x = int(input("Any number : "))
y = x // 7
s = (x // 10) - 1
for z in range(y):
    print(7*(z+1),end =",")
for z in range(s):
    print(((z+1)*10)+7,end =",")


x = int(input("Any number : "))
first = True
for i in range(1, x+1):
    if i % 7 == 0 or "7" in str(i):
        if not first:
            print(",", end="")
        print(i, end="")
        first = False
if first:
    print("no seven")

x = int(input("Any number : "))
true = True
for i in range(1,x+1):
    if i % 7 == 0 or "7" in str(i):
        if not true:
            print(",",end ="")
        print(i,end ="")
        true = False
if true:
    print("no seven")
