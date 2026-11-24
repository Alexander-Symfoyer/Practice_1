x = int(input())
y = int(input())
z = int(input())
if x > y and y > z:
    print("decreasing")
elif x < y and y < z:
    print("increasing")
else:
    print("neither")