y1 = int(input())
m1 = int(input())
d1 = int(input())
y2 = int(input())
m2 = int(input())
d2 = int(input())
if y1 == y2 and m1 == m2 and d1 == d2 :
    print(0)
elif y1 < y2 or (y1 == y2 and m1 < m2) or (y1 == y2 and m1 == m2 and d1 < d2):
    print(1)
else:
    print(2)