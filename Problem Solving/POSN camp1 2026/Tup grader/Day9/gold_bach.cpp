#include <bits/stdc++.h>
using namespace std;

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

    long long i = 0;
    long long j = n;
    while (i < j) {
        if (!sieve[i]) {
            i++;
            continue;
        }
        if (!sieve[j]) {
            j--;
            continue;
        }
        if (i + j == n) {
            cout << i << " " << j;
            return 0;
        }
        else if (i + j < n) {
            i++;
        }
        else if (i + j > n) {
            j--;
        }
    }

    return 0;
}