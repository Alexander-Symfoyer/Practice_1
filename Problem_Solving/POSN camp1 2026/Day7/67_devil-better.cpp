#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> damage(n+1);
    set<pair<int,int>> alive;

    long long sum_damage = 0;
    long long total_damage = 0;

    for (int i = 1; i <= n; i++) {
        int hp;
        cin >> hp >> damage[i];
        alive.insert({hp, i});
        sum_damage += damage[i];
    }

    int last_survivor = -1;
    while (!alive.empty()) {

        auto it = prev(alive.end());
        int hp = it->first;
        int idx = it->second;
        last_survivor = idx;

        total_damage += sum_damage;
        alive.erase(it);

        int new_hp = hp / 2;
        if (new_hp < 10) {
            sum_damage -= damage[idx];
        }
        else {
            auto same = alive.lower_bound({new_hp, 0});
            if (same != alive.end() && same->first == new_hp) {
                sum_damage -= damage[idx];
            }
            else {
                alive.insert({new_hp, idx});
            }
        }
    }

    std::cout << total_damage << " " << last_survivor << '\n';

    return 0;
}