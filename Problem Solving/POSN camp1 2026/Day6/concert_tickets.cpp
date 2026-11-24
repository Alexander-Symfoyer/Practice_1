#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;           //? n = tickets, m = customers
    cin >> n >> m;
    multiset<int> tick;
    vector<int> cust(m);
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        tick.insert(j);
    }
    for (int i = 0; i < m; i++) {
        cin >> cust[i];
    }

    for (int i = 0; i < m; i++) {
        auto it = tick.upper_bound(cust[i]);

        if (it == tick.begin()) {
            cout << -1 << '\n';
        }
        else {
            --it;
            cout << *it << '\n';
            tick.erase(it);
        }
    }

}