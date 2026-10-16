#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> found(n + 1, false);

    for (int i = 0; i < n - 1; i++) {
        int x;
        cin >> x;
        found[x] = true;
    }

    int m = found.size();
    for (int i = 1; i < m; i++) {
        if (!found[i]) {
            cout << i;
            return 0;
        }
    }
}