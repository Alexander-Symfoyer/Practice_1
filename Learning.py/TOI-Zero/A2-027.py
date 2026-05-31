n = int(input())
max_score = -1
top_count = 0
for i in range(n):
    score = int(input())
    if score > max_score:
        max_score = score
        top_count = 1
    elif score == max_score:
        top_count += 1 

print(max_score)
print(top_count)