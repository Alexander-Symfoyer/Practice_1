n = int(input())
values = [int(x) for x in input().split()]
sum = sum(values)
even = 0
odd = 0
for i in values:
    if i % 2 == 0:
        even += 1
    else:
        odd +=1
print("SUM",sum)
print("EVEN",even)
print("ODD",odd)