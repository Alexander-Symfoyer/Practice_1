direction = input()
x = 0
y = 0
for i in direction :
    if i == "N" :
        y += 1
    elif i == "S":
        y += -1
    elif i == "E":
        x += 1
    elif i == "W":
        x += -1
d = abs(x) + abs(y)
print(x,y,d)