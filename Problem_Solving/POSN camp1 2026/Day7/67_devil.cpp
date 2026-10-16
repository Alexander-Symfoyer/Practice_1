#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> health(n);
    vector<int> damage(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i] >> damage[i];
    }

    int count = n;
    long long total_damage = 0;
    vector<bool> remain(n, true);
    while (count > 1) {

        int index_h = 0;
        int max_h = INT_MIN;

        for (int i = 0; i < n; i++) {
            if (!remain[i]) continue;
            total_damage += damage[i];
        }

        for (int i = 0; i < n; i++) {
            if (!remain[i]) continue;
            max_h = max(max_h, health[i]);
        }

        for (int i = 0; i < n; i++) {
            if (!remain[i]) continue;
            if (health[i] == max_h) index_h = i;
        }

        health[index_h] /= 2;
        if (health[index_h] < 10) {
            remain[index_h] = false;
            count--;
        }
        else {
            for (int i = 0; i < n; i++) {
                if (!remain[i]) continue;
                if (i == index_h) continue;
                if (health[i] == health[index_h]) {
                    remain[index_h] = false;
                    count--;
                }
            }
        }

    }

    int index_l;
    for (int i = 0; i < n; i++) {
        if (remain[i] == true) {
            index_l = i;
            total_damage += damage[index_l];
        }
    }

    cout << total_damage << " " << index_l + 1 << '\n';

    return 0;
}