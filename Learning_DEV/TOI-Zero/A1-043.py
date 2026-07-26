base = int(input())
bonus = int(input())
streak = int(input())

total = 0
if streak <= 3:
    total = base + bonus
else:
    total = (base + bonus) * 1.5

secode = 0
if total >= 1500:
    secode = 5
elif 1000 <= total < 1500:
    secode = 4
elif 500 <= total < 1000:
    secode = 3
elif 200 <= total < 500:
    secode = 2
else:
    secode = 1

specode = 0
if secode == 5 and streak >= 7:
    specode = 99
elif secode == 4 and bonus > 300:
    specode = 88

print(int(total))
print(secode)
print(specode)