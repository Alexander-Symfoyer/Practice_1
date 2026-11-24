x,y = map(int,input().split())
jumps = 0
count = 0
while jumps < y or x > 0 :
    jumps += x  
    x -= 2
    count += 1
    
if jumps < y :
    print(-1)
else :
    print(count)