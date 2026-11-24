#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> number(n);
    for (int i = 0; i < n; i++) {
        cin >> number[i];
    }

    int round = 0;
    vector<bool> remain(n, true);
    int next = 1;

    while (next <= n) {
        int i = 0;
        while (i < n) {
            if (number[i] == next) {
                next++;
                i++;
            }
            else {
                i++;
            }
        }
        round++;
    }

    cout << round;

    return 0;
}