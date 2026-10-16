#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<pair<pair<int,string>,int>> que;
    int count = 0;

    while (true) {
        string s;
        int n;
        cin >> s;
        if (s == "end" || s == "END") break;
        cin >> n;
        que.push_back({{n, s}, count});
        count++;
    }

    sort(que.begin(), que.end(), [] (auto a, auto b) {
        if (a.first.first != b.first.first) {
            return a.first.first > b.first.first;
        }
        return a.second < b.second;
    });

    for (int i = 0; i < count; i++) {
        cout << que[i].first.second << " " << que[i].first.first << '\n';
    }

    return 0;
}