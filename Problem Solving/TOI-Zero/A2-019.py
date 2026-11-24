msg = input().strip()
msg2 = msg.lower()
n = len(msg2)

if "buu" in msg2:
    max_count = 0
    for i in range(n - 2):
        if msg2[i] == "b" and msg2[i + 1] == "u" and msg2[i + 2] == "u":
            cnt = 0
            j = i + 1
            while j < n and msg2[j] == "u":
                cnt += 1
                j += 1
            if cnt > max_count:
                max_count = cnt
    print("Yes", max_count)

elif "b" in msg2:
    out = []
    found_first_b = False
    for i in range(n):
        if msg2[i] == "b" and not found_first_b:
            out.append(msg[i])
            found_first_b = True
        elif found_first_b:
            out.append("U")
        else:
            out.append(msg[i])
    print("".join(out))
else:
    out = ("BUU" * 3)[:n]
    print(out)
