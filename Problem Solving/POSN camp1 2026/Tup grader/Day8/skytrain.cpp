#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,k;
    cin >> n >> k;
    int d = n;

    set<int> stations;
    priority_queue<pair<int,int>> pq;
    vector<bool> active;
    map<pair<int,int>,int> id;

    pq.push({n, 0});
    active.push_back(true);
    stations.insert(0);
    stations.insert(n);
    id[{0, n}] = 0;

    for (int i = 0; i < k; i++) {
        int station;
        cin >> station;
        
        auto right = stations.upper_bound(station);
        auto left = prev(right);

        int l = *left;
        int r = *right;

        int old_id = id[{l, r}];
        active[old_id] = false;

        id.erase({l, r});

        int id1 = active.size();
        active.push_back(true); 
        id[{l, station}] = id1;
        pq.push({station - l, id1});

        int id2 = active.size();
        active.push_back(true);
        id[{station, r}] = id2;
        pq.push({r - station, id2});

        stations.insert(station);

        while (!pq.empty() && !active[pq.top().second]) {
            pq.pop();
        }

        cout << pq.top().first << " ";

    }

    cout << '\n';

    return 0;
}