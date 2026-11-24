#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (long long i = 2; i <= n; i++) {
        for (long long j = i * i; j <= n; j += i) {
            sieve[j] = false;
        }
    }

    long long m = n;

    for (long long i = 2; i <= sqrt(m); i++) {
        if (!sieve[i]) continue;
        else {
            while (n % i == 0) {
                n /= i;
                cout << i << " ";
            }
        }
        if (n == 0) return 0;
    }

    return 0;
}