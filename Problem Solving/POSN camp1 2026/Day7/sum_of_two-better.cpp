#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++) {
       cin >> v[i].first;
       v[i].second = i + 1;
    }

    sort(v.begin(), v.end());
    int left = 0;
    int right = n - 1;
    while (left < right) {
        if (v[left].first + v[right].first > k) {
            right--;
        }
        else if (v[left].first + v[right].first < k) {
            left++;
        }
        else {
            cout << v[right].second << " " << v[left].second << '\n';
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}