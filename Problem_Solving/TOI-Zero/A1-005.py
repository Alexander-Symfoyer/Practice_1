month = int(input())
date = int(input())

if month == 1 or month == 2 or (month == 3 and date < 21) or (month == 12 and date >= 21):
    print("winter")
elif month == 4 or month == 5 or (month == 6 and date < 21) or (month == 3 and date >= 21):
    print("spring")
elif month == 7 or month == 8 or (month == 9 and date < 21) or (month == 6 and date >= 21):
    print("summer")
elif month == 10 or month == 11 or (month == 12 and date < 21) or (month == 9 and date >= 21):
    print("fall")