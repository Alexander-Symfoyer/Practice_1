#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n == 2) {
        int x,y;
        cin >> x >> y;
        cout << abs(x - y);
        return 0;
    }

    long long sum = 0;
    long long d = 0;

    for (int i = 0; i < n; i++ ) {
        long long x;
        cin >> x;

        d += 1LL * i * x - sum;
        sum += x;
    }

    long long mod = 49999;
    long long fact = 1;
    for (int i = 2; i <= n - 2; i++) {
        fact = fact * i % mod;
    }

    long long soln = (d % mod) * fact % mod;
    cout << soln;

    return 0;
}