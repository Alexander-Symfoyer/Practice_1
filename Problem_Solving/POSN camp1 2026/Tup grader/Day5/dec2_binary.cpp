#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n < 0 || n > 65536) return 0;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << "01";
        return 0;
    }
    string s;
    while (n > 0) {
        s += to_string(n & 1);
        n >>= 1;
    }
    reverse(s.begin(), s.end());
    cout << s;
}