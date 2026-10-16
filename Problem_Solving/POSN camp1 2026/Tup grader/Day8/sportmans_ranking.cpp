#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int,string>> athlete;
    int count = 0;
    for (int i = 0; i < n; i++) {
        int time;
        string name;
        cin >> name >> time;
        if (time < 3600) count++;
        athlete.push_back({time, name});
    }

    int swap_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (athlete[j].first > athlete[j+1].first) {
                swap(athlete[j], athlete[j+1]);
                swap_count++;
            }
        }
    }

    cout << swap_count << '\n';
    for (int i = 0; i < n; i++) {
        cout << i + 1 << " ";
        cout << athlete[i].second << " " << athlete[i].first;
        cout << '\n';
    }
    cout << count << '\n';

    return 0;
}