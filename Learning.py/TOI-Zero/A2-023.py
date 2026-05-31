msg = input().strip().lower()
allowed = "rabit"

first_bad = next((i for i, ch in enumerate(msg) if ch not in allowed), None)

if first_bad is not None:
    print("no", first_bad)
elif "b" not in msg and "r" not in msg and "a" not in msg:
    print("unknown", len(msg))
else:
    is_pure = True
    a_count = 0
    max_a_count = 0
    mistake = 0
    for i in range(len(msg)):
        if msg[i] == "a":
            a_count += 1
        else:
            if a_count > max_a_count:
                max_a_count = a_count
            a_count = 0
        if msg[i] == "r":
            if i == len(msg)-1 or msg[i+1] != "a":
                is_pure = False
                mistake = i if i == len(msg) - 1 else i + 1
                break
        if msg[i] == "a":
            if i == 0 or msg[i - 1] != "a":
                if i == 0 or msg[i - 1] != "r":
                    is_pure = False
                    mistake = i
                    break
        if msg[i] == "b":
            if i == len(msg)-1 or (msg[i+1] != "i" and msg[i+1] != "t"):
                is_pure = False
                mistake = i if i == len(msg) - 1 else i + 1
                break
    if is_pure :
        if a_count > max_a_count:
            max_a_count = a_count
        print("yes " + str(max_a_count))
    else:
        print("no " + str(mistake))