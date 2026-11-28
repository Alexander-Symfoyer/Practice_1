#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Chooses r things from n things
//! C(n,r) = C(n,r-1) + C(n-1,r-1)
//* Bottom-up (Pascal's Triangle)
//* O(nr)


ll bino(ll n, ll r, vector<vector<ll>>& table) {
    for (int i = 0; i <= n; i++) {      //* Base case
        table[i][0] = 1;
        if (i <= r) table[i][i] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i && j <= r; j++) {
            table[i][j] = table[i-1][j] + table[i-1][j-1];
        }
    }
    
    return table[n][r];
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