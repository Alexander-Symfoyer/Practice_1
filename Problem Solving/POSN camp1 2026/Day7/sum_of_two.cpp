#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    unordered_map<int, int> index;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        index[k - v[i]] = i + 1;
    }

    for (int i = 0; i < n; i++) {
        if (index.count(v[i]) && index[v[i]] != i + 1) {
            cout << i + 1 << " " << index[v[i]];
            return 0;
        }
    }

    cout << "IMPOSSIBLE";

    return 0;
}