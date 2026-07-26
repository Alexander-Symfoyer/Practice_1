import math

x1, y1, z1 = [int(x) for x in input().split()]
x2, y2, z2 = [int(x) for x in input().split()]

d = math.sqrt(((x2-x1)**2) + ((y2-y1)**2) + ((z2-z1)**2))
print(f"{d:.2f}")
