n = int(input())
count = 0
kgs = []
dict = {}
for i  in range(n):
    name,kg = input().split()
    kg = int(kg)
    
    if kg > 15:
        count += 1
    
    dict[kg] = name
    kgs.append(kg)

max_kg = max(kgs)

print(count)
print(f"{dict[max_kg]} {max_kg}")