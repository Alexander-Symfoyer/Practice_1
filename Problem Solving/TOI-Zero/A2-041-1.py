n = int(input())

def num2str(num):
    if num < 10 :
        return str(num)
    return chr((num - 10) + 65)

def convert(n, base):
    numerator = n
    output = ""
    while True:
        remainder = numerator % base
        output = num2str(remainder) + output
        numerator = numerator // base
        if numerator == 0:
            break
    
    return output

print(convert(n, 2))
print(convert(n, 8))
print(convert(n, 16))