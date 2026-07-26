n = int(input())
ten = n // 10
remain = n % 10
five = remain // 5
remain = remain % 5
two = remain // 2
remain = remain % 2
one = remain // 1

print(f"10 = {ten}")
print(f"5 = {five}")
print(f"2 = {two}")
print(f"1 = {one}")