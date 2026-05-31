w, h, m, n = [int(x) for x in input().split()]
a = [int(x) for x in input().split()]
b = [int(x) for x in input().split()]

v_size = []
previous = 0
for v in a:
    distance = v - previous
    previous = v
    v_size.append(distance)
v_size.append(w - previous)

h_size = []
previous = 0
for hh in b:
    distance = hh - previous
    previous = hh
    h_size.append(distance)
h_size.append(h - previous)

v_size.sort(reverse = True)
h_size.sort(reverse = True)

max_area1 = v_size[0] * h_size[0]
max_area2_1 = v_size[0] * h_size[1]
max_area2_2 = v_size[1] * h_size[0]
max_area2 = max([max_area2_1, max_area2_2])

print(f"{max_area1} {max_area2}")