n = int(input())
for i in range(n):
    if i == 0:
        print(0)
    else:
        row = "0 "
        for j in range(i-1):
            if i == n-1:
                row = row + "0 "
            else:
                row = row + "1 "
        row = row + "0"
        print(row)
