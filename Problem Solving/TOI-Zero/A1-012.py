num = int(input())
ope = input()
renum = (str(num)[::-1])
renum = int(renum)
if ope == "+":
    print(f"{num} + {renum} = {num+renum}")
elif ope == "*":
    print(f"{num} * {renum} = {num*renum}")