row, column = [int(x) for x in input().split()]
r_row, r_column = [int(x) for x in input().split()]

n = int(input())
storms = []
for i in range(n):
    storm = [int(x) for x in input().split()]
    storms.append(storm)
    
grid = [[0] * column for x in range(row)]

for storm in storms:
    sr, sc = storm
    for r in range(row):
        for c in range(column):
            dist = max(abs(r - sr), abs(c-sc))

            if dist == 0:
                risk = 100
            elif dist == 1:
                risk = 60
            elif dist == 2:
                risk = 20
            else:
                risk = 0

            grid[r][c] = max(grid[r][c], risk)

safe_count = 0
for r in range(row):
    for c in range(column):
        if grid[r][c] == 0:
            safe_count += 1

rabbit_risk = grid[r_row][r_column]

print(safe_count)
print(f"{rabbit_risk}%")
