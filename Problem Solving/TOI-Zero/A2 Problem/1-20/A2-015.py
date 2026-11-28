w,l,h = list(map(int, input().split()))
price_per_m = int(input())
total_length = (w + l) * h * 2
total_price = price_per_m * total_length
print(total_length)
print(total_price)