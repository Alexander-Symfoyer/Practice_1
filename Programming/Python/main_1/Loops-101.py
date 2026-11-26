# Guessing Game
#C = 17
#G = 0
#while G != C:
    #G = int(input("Please guess a number : "))
    #if G == C:
        #print("Correct!, Good Job!")
    #elif G >= C:
        #print("Too high!")
    #elif G <= C:
        #print("Too low!")

# Login System
#A = str(input("Username : "))
#B = int(input("Password : "))
#while A != "Luna" or B != 12:
    #A = str(input("Username : "))
    #B = int(input("Password : "))
#print("Login successful, Welcome Luna!")


print(list(range(10)))

for x in range(0):
    print("Hello",x)
    print("Hi",x)

#R = int(input("Please enter a number :"))
#sum = 0
#for x in range(R):
    #N = int(input("X"+str(x+1)+" : "))
    #sum += N
#print("Sum =",sum)


for i in range(0):
    print("Hello")
for i in range(0):
    print(i)

total = 0
for i in range(0):
    total += i
print(total)


x = 1
y = 2*x
print("2 x",x,"=",y)
x = x+1
y = 2*x
print("2 x",x,"=",y)

# Multiplication Table
for x in range(12):
    break
    for y in range(12):
        print(x+1, "x", y+1, "=", (x+1)*(y+1))
        

for A in "hello":
    if A == "l":
        continue
    print(A)
print("Done!")

for A in "hello":
    if A == "l":
        break
    print(A)
print("Done!")


#y = int(input("Any number :"))
#print(y,"STARS")
#print("*" * y)

y = int(input("Any number :"))
for x in range(y):
    print(x+1)
    print("*"*(x+1))


y = int(input("Enter a height: "))
for x in range(y):
    print(" "*(y-1-x) +"*"*(2*x+1))


for x in range(5):
    if x == 4:
        print(x+1,end="")
        break
    print(x+1,end="-")
    
