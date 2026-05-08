unit = int(input())
ft = 0.5 * unit
price = 0
if unit <= 10 :
    price = unit*5
elif unit <= 50:
    unit -= 10
    price = 50 + unit * 7
elif unit <= 100:
    unit -= 50
    price = 50 + 280 + unit * 10
elif unit <= 200:
    unit -= 100
    price = 50 + 280 + 500 + unit * 12
else:
    unit -= 200
    price = 50 + 280 + 500 + 1200 + unit * 15
vat = price * 7 / 100
total = price + ft + vat
print(f'{total:.2f}')