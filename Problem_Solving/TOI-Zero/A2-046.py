n = int(input())
vowel_set = {'a','e','i','o','u'}

for i in range(n):
    line = input().lower()
    
    vowel_count = 0
    consecutive_vowels = 0
    max_consecutive_vowels = 0
    
    for c in line:
        if c in vowel_set:
            vowel_count += 1
            consecutive_vowels += 1
        
        else:
            if consecutive_vowels > max_consecutive_vowels:
                max_consecutive_vowels = consecutive_vowels
            consecutive_vowels = 0
    
    if consecutive_vowels > max_consecutive_vowels:
        max_consecutive_vowels = consecutive_vowels

    print("Line %d: vowels = %d, max_consecutive = %d" % 
    (i + 1, vowel_count, max_consecutive_vowels))