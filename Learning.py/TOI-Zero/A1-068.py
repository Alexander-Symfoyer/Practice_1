n = int(input())
score = list(map(int, input().split()))

mean = sum(score) / n
min = min(score) 
print(f'{mean:.1f}')
if mean < 60 or min < 50:
    print("FAIL")
else:
    print("PASS")