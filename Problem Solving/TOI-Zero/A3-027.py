rows, cols = [int(x) for x in input().split()]

prev_row = ["-"] * cols
for i in range(rows):
    row = input().split()
    output = []
    for j in range(cols):
        cell = "-"
        if prev_row[j] == "*" or row[j] == "*":
            cell = "*"
        output.append(cell)
    print(" ".join(output))
    prev_row = row