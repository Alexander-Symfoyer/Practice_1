num_stores, num_queries = [int(x) for x in input().split()]
store_hours = []
for i in range(num_stores):
    start, stop = [int(x) for x in input().split()]
    store_hours.append((start, stop))
queries = [int(x) for x in input().split()]

answers = []
for q in queries:
    count = 0
    for s in store_hours:
        if s[0] <= q <= s[1]:
            count += 1
    answers.append(str(count))

print(" ".join(answers))