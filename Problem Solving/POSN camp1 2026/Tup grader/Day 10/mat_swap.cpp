#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    int count = 0;

    for (int i = 0; i < n; i++) {
        vector<int> v(m);
        for (int j = 0; j < m; j++) {
            cin >> v[j];
        }
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m - j - 1; k++) {
                if (v[k] > v[k+1]) {
                    swap(v[k], v[k+1]);
                    count++;
                }
            }
        }
    }

    cout << count << '\n';

    return 0;
}