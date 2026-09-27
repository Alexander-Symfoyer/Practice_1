#include <bits/stdc++.h>
using namespace std;
                                        //* Sieve Method
int count_primes(const int& n) {        //* O(n log long n)

    if (n <= 2) return 0;

    vector<bool> isprime(n, true);
    isprime[0] = false;                 //* 0 and 1 are not prime
    isprime[1] = false;

    for (int i = 2; i * i < n; i++) {
        if (isprime[i]) {                           //* If i is still marked as prime
            for (int j = i * i; j < n; j += i) {    //* Marked multiple
                isprime[j] = false;
            }
        }
    }

    int count = 0;
    for (bool prime : isprime) {
        if (prime) count++;
    }
    return count;

}

int main() {
    int n; 
    cin >> n;
    cout << count_primes(n);
}