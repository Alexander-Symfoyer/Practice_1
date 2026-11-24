#include <bits/stdc++.h>
using namespace std;

double min_total = DBL_MAX;

void search (int bought, double total, const int& k, 
    vector<bool>& used, vector<vector<double>> &land, const int& n, const int& m) {

    if (bought == k) {
        min_total = min(min_total, total);
        return;
    }

    for (int i = 0; i < k; i++) {
        if (used[i]) continue;

        int r = i / n;
        int c = i % n;
        double paid = land[r][c];

        used[i] = true;

        vector<vector<double>> old_land = land;

        for (int dr = -1; dr <= 1; dr++) {
            for (int dc = -1; dc <= 1; dc++) {

                if (dr == 0 && dc == 0) continue;
                int nr = r + dr;
                int nc = c + dc;

                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                land[nr][nc] += paid * 0.1;

            }
        }
    
        search(bought + 1, total + paid, k, used, land, n, m);

        land = old_land;
        used[i] = false;

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<vector<double>> land(m, vector<double>(n));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> land[i][j];
        }
    }

    int k = m * n;
    vector<bool> used(k, false);

    search(0, 0, k, used, land, n, m);

    cout << fixed << setprecision(2) << min_total << '\n';

}