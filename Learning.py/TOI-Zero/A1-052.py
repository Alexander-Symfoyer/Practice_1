cash = int(input())

if cash < 100 or cash > 20000 or cash % 100 != 0:
    print("ERROR")
else:
    bills = [1000, 500, 100]
    for bill in bills:
        count = cash // bill
        cash = cash % bill
        if count > 0:
            print(f"{bill} = {count}")





