#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        long long y,x;
        cin >> y >> x;
        long long k = max(y, x);
        
        if (k % 2 == 1) {
            if (x == k) {
                cout << k * k - y + 1 << '\n';
            }
            else {
                cout << (k * k - k + 1) - (k - x) << '\n';
            }
        }
        else {
            if (y == k) {
                cout << k * k - x + 1 << '\n';
            }
            else {
                cout << (k * k - k + 1) - (k - y) << '\n';
            }
        }
    }



    return 0;
}