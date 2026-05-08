n = int(input())
m = int(input())

for row in range(1, n+1):
    if n % 2 == 0:
        seat = "A" if row <= n // 2 else "K"
    else:
        upper = n // 2
        seat = "A" if (row <= upper or row == upper + 1) else "K"
    
    print(" ".join([seat] * m))

    