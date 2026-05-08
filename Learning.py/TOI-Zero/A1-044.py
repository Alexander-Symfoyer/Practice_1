age_day = input().split()
age = int(age_day[0])
day = age_day[1]
price = 0 
if age < 5:
    price = 0
elif age <= 18:
    price = 100
else:
    price = 150

if day == "Wed":
    price = price // 2
print(price)