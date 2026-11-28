size, type = input().split()
topping = input()
cost = 0

if size == "S":
    cost = 60
elif size == "M":
    cost = 80
else:
    cost = 100

if type == "T":
    cost += 20

if topping[0] != "N":
    topping_type, topping_amount = topping.split()
    topping_amount = int(topping_amount)
    if topping_type == "P":
        cost = cost + 15 * topping_amount
    elif topping_type == "E":
        cost = cost + 10 * topping_amount

print(cost)
