a = []
for i in range(5):
    row = [int(x) for x in input().split()]
    a.append(row)

bad_row = -1
for i in range(5):
    s = sum(a[i])
    if s % 2 != 0:
        bad_row = i

bad_col = -1
for i in range(5):
    s = 0
    for  j in range(5):
        s += a[j][i]
    if s % 2 != 0:
        bad_col = i

print(f"{bad_row} {bad_col}")