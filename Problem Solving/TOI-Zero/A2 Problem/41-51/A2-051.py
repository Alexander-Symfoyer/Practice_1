num_teams, num_members = [int(x) for x in input().split()]

if 0 >= num_teams or num_teams > 10 or 0 >= num_members or num_members > 20:
    print("Data Incorrect")
else:
    total_scores = 0
    for i in range(num_teams):
        scores = [int(x) for x in input().split()]
        max_scores = max(scores)
        average_scores = sum(scores) / num_members
        
        print("Team %d: Average = %.2f, Max = %d" %
        (i + 1, average_scores, max_scores))
        
        total_scores += sum(scores)
    
    print("Total Score of All Teams = %d" % total_scores)