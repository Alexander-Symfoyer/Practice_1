n = int(input())
roman = {1:"I", 2:"II", 3:"III", 4:"IV", 5:"V", 6:"VI", 7:"VII", 8:"VIII", 9:"IX"}
if 1 <= n <= 9:
    print(roman[n])
elif n == 0 or n >= 10:
    print("Error : Out of range")
else:
    print("Error : Please input positive number")