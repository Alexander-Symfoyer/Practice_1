#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;
    int count = 0;
    vector<int> chick(n);
    for (int i = 0; i < n; i++) {
        cin >> chick[i];
    }

    for (int k = l; k <= n; k++) {
        int prefix = 0;
        for (int j = 0; j < k; j++) {
            prefix += chick[j];
        }

        if (prefix == 0) count++;

        for (int i = 1; i + k <= n; i++) {
            prefix -= chick[i-1];
            prefix += chick[i+k-1];
            if (prefix == 0) count++;
        }
    }

    cout << count << '\n';

    return 0;
}