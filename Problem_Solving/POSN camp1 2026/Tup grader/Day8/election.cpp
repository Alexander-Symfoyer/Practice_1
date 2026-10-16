#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> n >> m;

    if (n < 1 || n > 1000 || m < 1 || m > 10) return 0;

    vector<int> count(m, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x-1]++;
    }

    for (int i = 0; i < m; i++) {
        cout << i + 1 << " " << count[i] << '\n';
    }

    return 0;
}

