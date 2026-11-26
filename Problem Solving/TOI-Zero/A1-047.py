per = int(input())
length = int(input())
total_min = per * length
hr = total_min // 60
min = total_min % 60
if total_min == 0 :
    print("No teaching")
else:
    output = ''
    delim = ''
    if hr > 0:
        output = str(hr) + ' hours'
        delim = ' '
    if min > 0:
        output += delim + str(min) +' minutes'
    print(output)