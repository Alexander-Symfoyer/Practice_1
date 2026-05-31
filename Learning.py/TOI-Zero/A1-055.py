a,b,c = map(int, input().split())

total_items = a + b + c
total_price = 25 * a + 40 * b + 55 * c

if total_items >= 3 :
    total_price = total_price * 90 // 100

print(total_price)