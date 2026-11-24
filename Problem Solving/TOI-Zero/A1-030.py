n = int(input())

output = ""
sum = 0

if n == 1:
    x,y = [int(x) for x in input().split()]
    print(max(x,y))
else:
    num = [int(x) for x in input().split()]
    for i in range(n):
        x,y = num[0],num[1]
        z = max(x,y)
        if i == n - 1:
            output += str(z)
        else:
            output += str(z) + " + "
        sum += z
        num.pop(0)
        num.pop(0)
    print(f"{output} = {sum}")

