r, h, g = [float(x) for x in input().split()]
wid = h + (r * 2)
hei = (2 * 3.14 * r) + g
print(f"{wid:.2f} {hei:.2f}")