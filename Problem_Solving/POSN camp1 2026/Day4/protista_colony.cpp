#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, days, e_per_food;
    cin >> n >> m >> days >> e_per_food;

    vector<int> foods;
    for (int i = 0; i < m; i++) {
        int food;
        cin >> food;
        foods.push_back(food);
    }

    vector<int> positions;
    vector<int> energys;
    vector<char> directions;

    for (int i = 0; i < n; i++) {
        int start, energy;
        cin >> start >> energy;

        positions.push_back(start);
        energys.push_back(energy);

        char direction;
        cin >> direction;
        directions.push_back(direction);
    }

    int remain;
    vector<bool> remains(n, true);

    for (int i = 0; i < days; i++) {

        for (int j = 0; j < n; j++) {
            if (!remains[j]) continue;

            if (directions[j] == 'L') {
                if (positions[j] - 1 < 1) {
                    remains[j] = false;
                    continue;
                }
                positions[j]--;
            }
            else {
                if (positions[j]+ 1 > m) {
                    remains[j] = false;
                    continue;
                }
                positions[j]++;
            }

        }
        
        for (int j = 0; j < n; j++) {
            if (!remains[j]) continue;

            int pos = positions[j];
            if (foods[pos - 1] > 0) {
                foods[pos - 1]--;
                energys[j] += e_per_food;
            }
            
            energys[j]--;
            if (energys[j] < 1) {
                remains[j] = false;
            }
        }

        for (int l = 0; l < positions.size(); l++) {
            for (int j = l + 1; j < positions.size(); j++) {
                if (!remains[j] || !remains[l]) continue;

                if (positions[l] == positions[j]) {
                    if (energys[l] > energys[j]) {
                        remains[j] = false;
                    }
                    else if (energys[j] > energys[l]) {
                        remains[l] = false;
                    }
                    else {
                        remains[j] = false;
                    }
                }
            }
        }

        for (int j = 0; j < foods.size(); j++) {
            foods[j]++;
        }
        
    }

    int counts = 0;
    for (int i = 0; i < remains.size(); i++) {
        if (remains[i]) counts++;
    }

    cout << counts << '\n';
    for (int i = 0; i < n; i++) {
        if (!remains[i]) continue;
        cout << i + 1 << " " << positions[i] << " " << energys[i] << " " << directions[i] << '\n';
    }

}

