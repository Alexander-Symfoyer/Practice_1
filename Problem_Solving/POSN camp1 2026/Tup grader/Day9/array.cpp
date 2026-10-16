#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> row(5, 0);
    vector<int> col(5, 0);

    vector<vector<int>> grid(5, vector<int>(5));
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> grid[i][j];
            row[i] += grid[i][j];
            col[j] += grid[i][j];
        }
    }

    int found = false;
    int ii, jj;

    for (int i = 0; i < 5; i++) {
        if (row[i] % 2 == 1) {
            ii = i;
            found = true;
        }
        if (col[i] % 2 == 1) {
            jj = i;
        }
    }

    if (!found) {
        cout << -1 << " " << -1 << '\n';
    }
    else cout << ii << " " << jj << '\n';

    return 0;
}