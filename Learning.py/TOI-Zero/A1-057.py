guest = int(input())
real = int(input())
if 1 <= guest <= 6 and 1 <= real <= 6:
    if guest == real:
        print("Correct!")
    else:
        print("Wrong!")
else:
    print("Invalid")