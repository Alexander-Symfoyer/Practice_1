pearl_type,pearl_amount = input().split()
pearl_amount = int(pearl_amount)
tea_type,sweetness,tea_cc = input().split()
sweetness = int(sweetness)
tea_cc = int(tea_cc)

pearl_per_g = {
    "H":5, "O":3, "J":2
}

tea_table = {
    "R" : {1:12, 2:18, 3:25},
    "T" : {1:15, 2:20, 3:30},
    "M" : {1:10, 2:15, 3:20}
}

cal_pearl = pearl_amount * pearl_per_g[pearl_type]
cal_tea = tea_cc * tea_table[tea_type][sweetness]
total_cal = cal_pearl + cal_tea

print(total_cal)









