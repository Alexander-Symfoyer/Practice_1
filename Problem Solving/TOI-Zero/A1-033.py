n = int(input())
count = 0
v = ["A","E","I","O","U"]
for i in range(n):
    c = input()
    if c in v:
        count += 1
print(count)