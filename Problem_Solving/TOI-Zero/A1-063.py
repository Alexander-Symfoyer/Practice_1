seats = int(input())
remain = seats

while True:
    try:  
        ages, tickets = map(int, input().split())
    except:
        break
    
    if ages < 15:
        print(-1)
        continue
    
    if tickets > remain:
        print(-2)
        break

    remain -= tickets

    if 15 <= ages <= 22:
        price = int(150 * 0.8 * tickets)
        print(f"{price} {remain}")
    elif ages >= 60:
        price = int(150 * 0.5 * tickets)
        print(f"{price} {remain}")
    else:
        price = 150 * tickets
        print(f"{price} {remain}")

    