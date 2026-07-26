from collections import Counter

n = int(input())
sizes = [int(input()) for _ in range(n)]

counter = Counter(sizes)
print(counter)

max_counter = max(counter.values())
print(max_counter)