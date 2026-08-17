n = int(input())
heights = list(map(int, input().split()))
count = 0
for i,h in enumerate(heights):
    if (i == 0 or h > heights[i-1]
    ) and (
        i == len(heights) - 1 or h > heights[i+1]):
        
        count += 1

print(count)
    
    