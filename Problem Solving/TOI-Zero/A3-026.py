rows, cols = [int(x) for x in input().split()]

def combine(s1, s2):
    if s1 == "-" and s2 == "-":
        return "-"
    elif s1 == "-" and s2 == "+":
        return "+"
    elif s1 == "-" and s2 == "x":
        return "x"
    elif s1 == "+" and s2 == "x":
        return "*"
    elif s1 == "+" and s2 == "+":  
        return "+"
    elif s1 == "x" and s2 == "x": 
        return "x"
    elif s1 == "+" and s2 == "-":
        return "+"
    elif s1 == "x" and s2 == "-":
        return "x"
    elif s1 == "x" and s2 == "+":
        return "x"

imagel = []
for i in range(rows):
    imagel.append(input())

for i in range(rows):
    pixels1 = list(imagel[i])
    pixels2 = list(input())
    output_row = ""

    for j in range(cols):
        output_pixel = combine(pixels1[j], pixels2[j])
        output_row = output_row + output_pixel
    print(output_row)