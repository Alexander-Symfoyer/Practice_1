#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> up(n, vector<int>(n));
    vector<vector<int>> down(n, vector<int>(n));
    vector<vector<int>> left(n, vector<int>(n));
    vector<vector<int>> right(n, vector<int>(n));

    

    return 0;
}