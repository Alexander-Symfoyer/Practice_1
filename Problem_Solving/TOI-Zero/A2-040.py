n = int(input())
input_lines = []

for i in range(n):
    input_lines.append(input())

for i in range(n):
    row1 = [int(x) for x in input_lines[i].split()]
    row2 = [int(x) for x in input().split()]

    output_row = []
    for i in range(len(row1)):
        sum = row1[i] + row2[i]
        output_row.append(str(sum))
    
    print(" ".join(output_row))
