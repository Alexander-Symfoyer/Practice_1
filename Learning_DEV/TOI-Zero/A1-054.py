values = input().split()

position = values[0]
years = int(values[1])
salary = int(values[2])

bonus = 0

if position == "M":
    bonus = 1500
    if years < 5:
        bonus += salary * 0.06
    elif years <= 10:
        bonus += salary * 0.08
    else:
        bonus += salary * 0.10

elif position == "B":
    bonus = 1000
    if years < 5:
        bonus += salary * 0.05
    elif years <= 10:
        bonus += salary * 0.06
    else:
        bonus += salary * 0.07

elif position == "G":
    bonus = 500
    if years < 5:
        bonus += salary * 0.04
    elif years <= 10:
        bonus += salary * 0.05
    else:
        bonus += salary * 0.06

else:
    bonus = 0

print(int(bonus))