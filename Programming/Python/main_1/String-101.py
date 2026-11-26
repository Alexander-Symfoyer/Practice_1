text = "Hello"
print(text[0]+text[1]+text[2]+text[3])
print(text[0:4])
print(text[1:])
print(text[:4])
print("Hell" in text)
print("King" not in text)

A = "Jeck"
B = "Cat"
C = "Dog"
D = 67
E = 67.2343452
F = True
print("My name is %s and i love %s and %s." %(A,B,C))
print("I like number %d" %(D))
print("The price is %f" %(E))
print("The price is %.2f" %(E))
print("This is %r" %(F))

#x = str(input("Firstname : ")).capitalize()
#y = str(input("Lastname : ")).capitalize()
#print("Your full name is %s %s."%(x,y))

x = "Pram"
y = "Welcome %s"%(x)
A = len(y)
B = (20 - len(y)) / 2
print(int(B))
print(len(y))
print(y.center(20,"-"))

x = "mathmatics"
print(x.count("m"))
print(x.count("t",2,8))

x = "fitness"
print(x.find("s"))
print(x.find("k"))
print(x.index("i"))

x = "101"
y = "A12CE4"
print(x.isdecimal())
print(y.isdecimal())