n = int(input())
output = ""
for i in range(n):
    if (i + 1) % 5 == 0:
        output += "X"
    else:
        output += "*"
print(output)