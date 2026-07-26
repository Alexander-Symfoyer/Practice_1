card = input().upper()
spec = {"A":"ace", "J":"jack", "Q":"queen", "K":"king"}
sym = {"D":"diamonds", "H":"hearts", "S":"spades", "C":"clubs"}
special = ["A","J","Q","K"]
if card[0] in special:
    print(f"{spec[card[0]]} of {sym[card[-1]]}")
else:
    if len(card) == 3:
        print(f"10 of {sym[card[-1]]}")
    else:
        print(f"{card[0]} of {sym[card[-1]]}")