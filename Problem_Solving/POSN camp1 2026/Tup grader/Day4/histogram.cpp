#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> count(9, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        count[x - 1]++;
    }

    for (int i = 1; i <= 9; i++) {
        cout << i << "|";
        for (int j = 0; j < count[i - 1]; j++) {
            cout << "*";
        }
        cout << '\n';
    }

    return 0;
}