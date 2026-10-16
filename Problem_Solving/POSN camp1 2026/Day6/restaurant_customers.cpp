#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    unordered_map<int, int> count;
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;
        for (int i = x; i <= y; i++) {
            count[i]++;
        }
    }

    int max_value = INT_MIN;
    for (auto [key, value] : count) {
        max_value = max(value, max_value);
    }

    cout << max_value << '\n';

}