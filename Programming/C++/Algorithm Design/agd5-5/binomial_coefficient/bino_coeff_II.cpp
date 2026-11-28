#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Chooses r things from n things
//! C(n,r) = C(n,r-1) + C(n-1,r-1)
//* Top-down
//* O(nr)


ll bino(ll n, ll r, vector<vector<ll>>& table) {
    if (r == n) return 1;
    if (r == 0) return 1;

    if (table[n][r] != -1) {
        return table[n][r];     //! Memoization
    }

    ll result = bino(n-1, r, table) + bino(n-1, r-1, table);
    table[n][r] = result;       //! Memoization

    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll r, n;
    cin >> n >> r;
    if (r > n || r < 0 || n < 0) return 0;

    vector<vector<ll>> table(n+1, vector<ll>(r+1, -1));
    cout << bino(n, r, table);
}