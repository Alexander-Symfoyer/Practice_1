n = input().split()
output = ""
symbol = ["#","/","+","*"]
for i in n:
    if i == "0":
        output += "-"
        continue
    for x, y in enumerate(i):
        if y == "0":
            output += ""
        else :
            output += symbol[x - len(i)]
print(output)