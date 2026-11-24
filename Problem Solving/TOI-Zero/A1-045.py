km = int(input())
price = 35
if km > 1:
    price = 35 + ((km - 1) * 5)
if km > 10:
    price = 80 + ((km - 10) * 8)
print(price)