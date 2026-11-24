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
    unordered_map<int,int> count;
    for (int i = 0; i <= 10; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
            count[grid[i][j]]++;
        }
    }

    int max_count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (count[grid[i][j]] < 4) continue;
            int count = 0;
            int p1 = 1;
            while (j + p1 < n &&
                    j - p1 >= 0 &&
                    i + p1 < n &&
                    i - p1 >= 0) {

                if (grid[i][j + p1] != grid[i][j] ||
                    grid[i][j - p1] != grid[i][j] ||
                    grid[i + p1][j] != grid[i][j] ||
                    grid[i - p1][j] != grid[i][j]) {
                        break;
                }
                count++;
                p1++;
            }
            max_count = max(max_count, count);
        }
    }

    cout << max_count;

    return 0;
}