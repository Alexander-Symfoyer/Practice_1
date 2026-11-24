#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, lucky;
    cin >> n >> lucky;
    vector<pair<pair<int, int>, int>> prison;

    vector<int> danger;

    for (int i = 0; i < n; i++) {
        int age, level;
        cin >> age >> level;
        prison.push_back({{level, age}, i + 1});
        if (age >= 6) {
            danger.push_back(i);
        }
    }

    sort(prison.begin(), prison.end(), [] (auto a, auto b) {
        if (a.first.first != b.first.first) {
            return a.first.first > b.first.first;
        }
        return a.second < b.second;
    });

    vector<bool> remain(n + 1, true);
    for (int i =  0; i < n; i++) {
        if (prison[i].first.first >= 6) {
            remain[i] = false;
        }
        else if (prison[i].first.second >= 25) {
            remain[i] = false;
        }
        else if (prison[i].first.second % lucky != 0) {
            remain[i] = false;
        }
    }

    for (int i = 0; i < n; i++) {
        if (prison[i].first.first < 6 && !remain[i]) {
            cout << prison[i].second << " ";
        }
    }   cout << '\n';


    
    return 0;
}