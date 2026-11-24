n = int(input())
ps = []
vs = []
for i in range(n):
    p,v = [int(x) for x in input().split()]
    ps.append(p)
    vs.append(v)

count = 0
current_max_v = vs[n-1]
for i in range(n - 2, -1, -1):
    if vs[i] <= current_max_v:
        count +=1
    else:
        current_max_v = vs[i]

print(count)
