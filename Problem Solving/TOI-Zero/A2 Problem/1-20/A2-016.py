c1,n1 = input().split()
c2,n2 = input().split()

if c1 == c2 and n1 == n2:
    print(1000000)
elif c1 != c2 and n1 == n2:
    print(100000)
elif c1 == c2 and n1[2:6] == n2[2:6]:
    print(2000)
elif c1 == c2 and n1[3:6] == n2[3:6]:
    print(1000)
elif c1 != c2 and n1[2:6] == n2[2:6]:
    print(200)
elif c1 != c2 and n1[3:6] == n2[3:6]:
    print(100)
elif c1 == c2 and n1 != n2:
    print(20)
else:
    print(0)