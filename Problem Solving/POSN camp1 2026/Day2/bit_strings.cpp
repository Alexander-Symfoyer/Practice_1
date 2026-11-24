#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long soln = 1;
    const long long mod = 1000000007;
    for (int i = 0; i < n; i++) {
        soln = (soln * 2) % mod;
    }
    cout << soln << '\n';

    return 0;
}