color,n = input().split()
n = int(n)
colors = ["Red","Green","Blue"]
output = []
offset = 0
if color == "G":
    offset = 1
elif color == "B":
    offset = 2

for i in range(n):
    output.append(colors[(i + offset) % 3])
print(*(output))