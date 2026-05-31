ad = int(input())
cc = int(input())
tax = 0
if ad <= 1990 :
    if cc <= 1500:
        tax = 1250
    elif 1500 < cc <= 2000:
        tax = 1400
    else:
        tax = 2000
elif 1990 < ad < 2000:
    if cc <= 1500:
        tax = 1100
    elif 1500 < cc <= 2000:
        tax = 1300
    else:
        tax = 1700
else:
    if cc <= 1500:
        tax = 1000
    elif 1500 < cc <= 2000:
        tax = 1200
    else:
        tax = 1500
print(tax)