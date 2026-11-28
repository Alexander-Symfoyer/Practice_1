code = input()
count = 0
output = ""
for i in range(len(code)):
    c = code[i]
    if i == 0 or code[i-1] == c:
        count += 1
    else:
        output = output + str(count) + code[i-1]
        count = 1
output = output + str(count) + code[len(code)-1]
print(output)
