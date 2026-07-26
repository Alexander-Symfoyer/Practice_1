degree = int(input())
unit = input().lower()
if unit == "c":
    if degree <= 0 :
        print("solid")
    elif degree < 100:
        print("liquid")
    else:
        print("gas")
else:
    if degree <= 32 :
        print("solid")
    elif degree < 212:
        print("liquid")
    else:
        print("gas")