#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> events(2*n);
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        events[2*i] = {a, 1};
        events[2*i+1] = {b, -1};
    }

    sort(events.begin(), events.end());
    int current = 0;
    int soln = 0;

    for (auto e : events) {
        current += e.second;
        soln = max(soln, current);
    }

    cout << soln << '\n';

}