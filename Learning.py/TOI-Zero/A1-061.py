r, x, y =[int(x) for x in input().split()]
xy = (x**2) + (y**2)
rr = r**2
if xy < rr:
    print("IN")
elif xy > rr:
    print("OUT")
else:
    print("ON")