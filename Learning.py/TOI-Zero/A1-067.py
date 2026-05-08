char = input().strip()
n = int(input())
total = 0

for i in range(n):
    price = float(input())
    total += price

if char == "Y":
    print(f"{(total * 0.95):.2f}")
elif char == "N" and total >= 500:
    print(f"{(total * 0.97):.2f}")
else:
    print(f"{total:.2f}")
