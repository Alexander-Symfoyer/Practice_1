origin,destination = input().split()
weight = int(input())
routes = {
    ("BKK","CNX") : (10,30),
    ("CNX","UBP") : (15,40),
    ("UBP","BKK") : (20,40),
    ("BKK","PKT") : (25,50),
    ("PKT","CNX") : (30,60),
    ("UBP","PKT") : (40,70)
}

if (origin,destination) in routes and 1 <= weight <= 10000:
    base_fee, per_kg_fee = routes[(origin,destination)]
    total = base_fee + per_kg_fee * weight
    print(total)
else:
    print("Error")