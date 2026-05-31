n = int(input())
sizes = []
for i in range(n):
    sizes.append(int(input()))

sizes.sort()
max_count = 0
for size in set(sizes):
    count = sizes.count(size)
    max_count = max(max_count, count)

print(max_count)
    