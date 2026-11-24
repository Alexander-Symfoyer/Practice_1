numbers = input().split()
output = []

for n in numbers:
    if n not in output:
        output.append(n)

print(*output)
print(" ".join(output))