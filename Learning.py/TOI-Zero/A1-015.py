fn = input()
ln = input()
age = input()
if len(fn) > 5 and len(ln) > 5:
    print(fn[:2] + ln[-1] + age[-1])
else:
    print(fn[0] + age + ln[-1] )