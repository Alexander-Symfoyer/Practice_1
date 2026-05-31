distance, n = [int(x) for x in input().split()]
rd, md, fd = [int(x) for x in input().split()]

checkpoint = {}
for i in range(n):
    cp_d, cp_score = [int(x) for x in input().split()]
    checkpoint[cp_d] = cp_score


def compute_score(total_distance, leap_distance):
    current_location = 0
    current_score = 0
    
    while current_location <= total_distance:
        if current_location in checkpoint:
            current_score += checkpoint[current_location]
        current_location += leap_distance
    
    return current_score


r_score = compute_score(distance, rd)
m_score = compute_score(distance, md)
f_score = compute_score(distance, fd)

max_score = max([r_score, m_score, f_score])

if r_score == max_score:
    print(f"Rabbit {r_score}")
if m_score == max_score:
    print(f"Monkey {m_score}")
if f_score == max_score:
    print(f"Frog {f_score}")
