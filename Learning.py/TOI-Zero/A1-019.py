x = input()
y = input()
z = input()
if x == y == z and x == z:
    print("all the same")
elif x != y != z and x != z:
    print("all different")
else:
    print("neither")