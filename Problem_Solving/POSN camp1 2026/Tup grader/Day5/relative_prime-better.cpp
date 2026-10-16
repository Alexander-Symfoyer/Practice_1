#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;

        while (b != 0) {
           int r = a % b;
           a = b;
           b = r;
        }

        if (a != 1) cout << "N" << '\n';
        else cout << "Y" << '\n';

    }
}