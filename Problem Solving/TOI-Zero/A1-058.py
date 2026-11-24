n = int(input())
summation = 0
max_cups = -1
min_cups = 1001

for i in range(n):
    cups = int(input())
    summation += cups
    if cups > max_cups:
        max_cups = cups
    if cups < min_cups:
        min_cups = cups

mean = summation / n

print(summation)
print(max_cups)
print(min_cups)
print(f'{mean:.1f}')