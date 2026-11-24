#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    if (n >= 1) {
        cout << 0 << '\n';
    }
    long long multi = 0;
    long long add = 1;
    for (long long i = 2; i <= n; i++) {
        cout << (((i * i) * (i * i - 1)) / 2) - (8 * multi) << '\n';
        multi += add;
        add++;
    }

    return 0;
}