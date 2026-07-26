n = int(input())
id1 = input()
id2 = input()
count = 0
not_count = n

for i in range(n):
    if int(id1[i]) + int(id2[i]) == 9:
        count += 1
    else:
        not_count -= 1

if count == n:
    print("YES")
else:
    print(f"NO {n - not_count}")