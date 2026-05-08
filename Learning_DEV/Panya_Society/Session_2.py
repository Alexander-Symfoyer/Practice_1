b = [2,4,6,8]
b[2] = b[0] * b[1] -3
print(b)

w = "butterfly"
print(w[:2]+(w[7]*2)+w[8])

a = [1,2,3,4]
b = 5
print(f"A is {a[2]}, B is {b}")

d = [1,4,7,8,10,12]
for i in d :
    if i % 2 != 0:
        print(i)

print("-------------------------------")

c =[1,2,3,4,5]
for i in c:
    i += 1
    print(i)

print("-------------------------------")

e = [1,2,3,4,10,11,12,13]
for i,x in enumerate(e):
    if i > 5 :
        print(f"position = {i} , value = {x}")   

f = [1,3,6,8,10,15]
g = [x for x in f if x < 8]
print(g)
h = [x*2 for x in f ]
print(h)