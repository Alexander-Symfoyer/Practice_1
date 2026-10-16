#include <bits/stdc++.h>
using namespace std;
int main() {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,s,d,r;
    cin >> n >> s >> d >> r;
    vector<bool> sieve(n + 1, true);
    sieve[0] = false;
    sieve[1] = false;
    for (long long i = 2; i <= n; i++) {
        for (long long j = i * i; j <= n; j += i) {
            sieve[j] = false;
        }
    }
    
    int count = 0;
    if (r == 1) {
        for (int i = s; i <= n; i += d) {
            if (sieve[i]) {
                count++;
            }
        }
    }
    else if (r == -1) {
        for (int i = s; i >= 2; i -= d) {
            if (sieve[i]) {
                count++;
            }
        }
    }
    
    cout << count;
    
}