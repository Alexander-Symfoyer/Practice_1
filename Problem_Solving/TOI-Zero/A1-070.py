n = int(input())
for i in range(n):
    p,c,g = list(map(float, input().split()))
    all = p + c + g
    output = str(all)
    if all > 50:
        output += ",Overloaded"
    if p > 20:
        output += ",Check Type Plastic"
    if c > 20:
        output += ",Check Type Can"
    if g > 20:
        output += ",Check Type Glass"
    print(output)