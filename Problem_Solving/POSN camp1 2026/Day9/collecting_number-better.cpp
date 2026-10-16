#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    int round = 1;
    vector<int> pos(n + 1);

    for (int i = 0; i < n; i++) {
        pos[number[i]] = i;
    }

    for (int j = 0; j < n; j++) {
        if (pos[j] > pos[j + 1]) {
            round++;
        }
    }

    cout << round;

    return 0;
}