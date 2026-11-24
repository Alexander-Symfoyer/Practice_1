n = int(input())
coins = [10,5,2,1]
for coin in coins:
    print(f"{coin} = {n // coin}")
    n = n % coin