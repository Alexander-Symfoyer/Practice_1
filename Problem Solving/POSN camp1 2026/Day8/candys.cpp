#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    int x,y,l;
    cin >> x >> y >> l;
    string s;
    cin >> s;

    long long sum = 0;
    for (const char& c : s) {
        if (c == 'U') {
            y--;
        }
        else if (c == 'D') {
            y++;
        }
        else if (c == 'R') {
            x++;
        }
        else if (c == 'L') {
            x--;
        }
        else if (c == 'X') {
            sum += grid[y-1][x-1];
        }
    }

    cout << sum;

    return 0;
}