cal = {1:100, 2:120, 3:200, 4:60}
sum = 0
while True:
    order = int(input())
    if order == 5:
        break
    sum += cal[order]
print("Bye Bye")
print(f"Total Calories: {sum}")