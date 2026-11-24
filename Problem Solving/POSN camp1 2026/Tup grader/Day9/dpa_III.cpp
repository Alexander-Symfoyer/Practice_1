#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n < 3 || n > 10000) return 0;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < 2 || x > 100000) return 0;
        long long sum = 1;
        for (long long j = 2; j < x; j++) {
            if (x % j == 0) {
                sum += j;
            }
        }
        if (sum == x) cout << "P" << '\n';
        else if (sum < x) cout << "D" << '\n';
        else cout << "A" << '\n';
    }

    return 0;
}