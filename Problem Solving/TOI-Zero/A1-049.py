fake = input()
fakes = [int(fake[i]) for i in range(5)]

floors = [9,10,11,12,14]
floor = 13
for i in range(5):
    if fakes[i] > 5:
        floor = floors[i]
        break

room = ""
if fake == fake[::-1]:
    if fakes[0] + fakes[4] > 5:
        room += "1"
    elif fakes[1] * fakes[3] > 5:
        room += "2"
    else:
        room += "0"
else:
    if fakes[4] != 0  and fakes[0] // fakes[4] > 5:
        room += "1"
    elif fakes[1] - fakes[4] > 5:
        room += "2"
    else:
        room += "0"

if sum(fakes) > 25:
    room += "1"
elif fakes[0] * fakes[1] * fakes[2] * fakes[3] * fakes[4] > 55 :
    room += "2"
else:
    room += "0"

real = str(floor) + room
print(real)




