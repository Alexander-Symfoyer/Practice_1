#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    for (int i = 0; i < (1 << n); i++) {
        int gray = i ^ (i >> 1);
        for (int bit = n - 1; bit >= 0; bit--)  {
            cout << ((gray >> bit) & 1);
        }   cout << '\n';
    }

    return 0;
}