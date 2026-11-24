#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n < 1 || n > 40) return 0;
    vector<string> v(n);
    unordered_map<string, int> count;

    for (int i = 0; i <= 9; i++) {
        count["0" + i] == i;
    }

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        for (int j = 0; j < v[i].size(); j++) {
            count[v[i]]++;
        }
    }

    for (int i = 0; i <= 9; i++) {
        cout << i << '|';
        for (int i = 0; i < count["0" + i]; i++) {
            cout << "*";
        }
        cout << '\n';
    }
    
}