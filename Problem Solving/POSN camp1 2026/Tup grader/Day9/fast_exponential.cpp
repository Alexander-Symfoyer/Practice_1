#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, mod;
    cin >> a >> b >> mod;

    long long expo = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            expo = expo * a % mod;
        }
        a = a * a % mod;
        b /= 2;
    }

    cout << expo;

    return 0;
}