name1 = input().lower()
name2 = input().lower()
max_len = max(len(name1), len(name2))

if len(name1) < max_len:
    diff = max_len - len(name1)
    extra = "".join(name1[j % len(name1)] for j in range(diff))
    name1 = name1 + extra

if len(name2) < max_len:
    diff = max_len - len(name2)
    extra = "".join(name2[j % len(name2)] for j in range(diff))
    name2 = name2 + extra

output = []
w_count = 0
consec_w_count = 0
max_consec_w_count = 0
love = ["l", "o", "v", "e"]

for i in range(len(name1)):
    c1 = name1[i]
    c2 = name2[i]
    if c1 in love or c2 in love:
        output.append("w")
        w_count += 1
        consec_w_count += 1
    else:
        output.append("$")
        if consec_w_count > max_consec_w_count:
            max_consec_w_count = consec_w_count
        consec_w_count = 0

if consec_w_count > max_consec_w_count:
    max_consec_w_count = consec_w_count

if w_count % 2 == 0:
    if max_consec_w_count < 2:  
        output.append("#")
else:
    output.append(str(max_consec_w_count))

print("".join(output))
