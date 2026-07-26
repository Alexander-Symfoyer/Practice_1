males = ["1","3","5","7","9"]
famales = ["0","2","4","6","8"]
male = 0 
famale = 0
keycard = [x for x in input().split()]
for i in keycard:
    if int(i) < 0 :
        break
    elif i[-1] in males:
        male += 1
    elif i[-1] in famales:
        famale += 1

print(f"{male} {famale} {male + famale}")