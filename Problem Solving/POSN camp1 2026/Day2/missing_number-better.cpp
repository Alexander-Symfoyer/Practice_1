#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long expected = n * (n + 1) / 2;
    long long actual = 0;
    for (int i = 0; i < n - 1; i++) {
        long long x;
        cin >> x;
        actual += x;
    }

    cout << expected - actual << '\n';

    return 0;
}