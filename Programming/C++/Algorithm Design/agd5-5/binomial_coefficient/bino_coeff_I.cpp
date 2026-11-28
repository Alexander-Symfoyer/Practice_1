#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Chooses r things from n things
//? C(n,r) = n!/(r!*(n-r!))
//! C(n,r) = C(n,r-1) + C(n-1,r-1)
//? r = 0, r = n --> result = 1
//* O(2^n)

int bino(int n, int r) {
    if (r == n) return 1;
    if (r == 0) return 1;
    int result = bino(n-1, r) + bino(n-1, r-1);
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, n;
    cin >> n >> r;
    cout << bino(n, r);
}