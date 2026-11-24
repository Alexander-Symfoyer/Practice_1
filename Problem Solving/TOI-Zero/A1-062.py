def is_prime(n):
    if n < 2:
        return False
    
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    
    return True


s, e = [int(x) for x in input().split()]
primes = []
for n in range(s, e + 1):
    if is_prime(n):
        primes.append(n)

print(*(primes))
print(f"Total primes: {len(primes)}")