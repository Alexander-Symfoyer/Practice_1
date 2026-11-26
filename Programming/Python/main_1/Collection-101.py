A = [0,1,2,3,4]
for i in A:
    print(i)
print("--------------------------")
for i in range(5):
    print(i)

x = ["Alex","Jackey","Joey"]
print(x[0])
print(x[0:])

x.append("Pun")
print(x)

x.remove("Jackey")
print(x)

del x[1]
print(x)

x[0] = "Yami"
print(x)

print("----------------------------------------")

B = ("Noel","Asta","Yuno")
print(B)
print(B[1])
print(B[:2])
print(B[1:3])

x = ("Finral","Vanessa")
y = B + x
print(y)
print(y*2)

print("Asta" in y)
print("Yuno" not in y)

for i in y:
    print("Hello",i)

print("-------------------------------------")

z = (1,2,97,67,1009,4,61,127,0,-76)
print(len(z))
print(max(z))
print(min(z))
print(z.index(4))
print(list(z))
print(tuple(A))

print("_______________________________________")

C = {'Name':'Gosh','Height':184}
print(C)
print(C['Name'])
print(C['Height'],"cm")

C['Weight'] = 65
print(C)

C['Name'] = "Luck"
print(C['Name'])

print(len(C))
print(type(C))
print(C.items())

for i in  C.keys():
    print(i)

for i in C.values():
    print(i)

C.clear()
print(C)