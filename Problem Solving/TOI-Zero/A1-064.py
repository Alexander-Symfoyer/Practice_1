data = input().split()
n = int(data[0])  
score = 0
commands = data[1:n+1]

for cmd in commands:
    if cmd == "+":
        score += 10
    elif cmd == "-":
        score -= 5
print(score)
