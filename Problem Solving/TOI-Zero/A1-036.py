n = int(input())
list = []
remain = n // 10 * 10
for i in range((n // 10) + 1):
    list.append(str(remain))
    remain -= 10
print(" ".join(list))