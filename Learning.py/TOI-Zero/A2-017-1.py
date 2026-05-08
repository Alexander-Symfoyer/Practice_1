ramen_size,ramen_type = input().split()
top = input()

ramen_table = {
    "S" : {"R":60, "T":80},
    "M" : {"R":80, "T":100},
    "L" : {"R":100, "T":120}
}
top_table = {"P":15,"E":10}

ramen_price = 0
if top == "N":
    ramen_price = ramen_table[ramen_size][ramen_type]
    print(ramen_price)
else:
    top_type,top_amount = top.split()
    top_amount = int(top_amount)
    ramen_price = ramen_table[ramen_size][ramen_type]
    ramen_price += top_table[top_type] * top_amount
    print(ramen_price)









