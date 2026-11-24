#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n <= 1 || n >= 10000) return 0;
    unordered_set<int> seen;
    for (int i = 0; i < n; i++) {
        int j;
        cin >> j;
        if (j <= 0 || j >= 10000) return 0;
        if (seen.find(j) == seen.end()) {
            cout << j << " ";
        }
        seen.insert(j);
    }



}