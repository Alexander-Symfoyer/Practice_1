#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    set<pair<int, string>> data;
    int maxx = INT_MIN;
    int count = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int x;
        cin >> s >> x;
        data.insert({x, s});
        if (x > 15) count++;
    }

    cout << count << '\n';
    cout << data.rbegin()->second << " ";
    cout << data.rbegin()->first;

    return 0;
}