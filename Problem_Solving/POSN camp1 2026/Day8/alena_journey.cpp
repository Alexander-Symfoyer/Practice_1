#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n,m,k;
    cin >> n >> m >> k;

    if (k == 1) {
        cout << "yes";
        return 0;
    }

    int current_i, current_j;
    vector<vector<int>> village(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> village[i][j];
            if (village[i][j] == 1) {
                current_i = i;
                current_j = j;
            }
        }
    }

    int next = 2;
    string directions = "";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (current_j - 1 >= 0 && village[current_i][current_j - 1] == next) {
                current_j--;
                next++;
                directions += 'L';
            }
            else if (current_j + 1 < m && village[current_i][current_j + 1] == next) {
                current_j++;
                next++;
                directions += 'R';
            }
            else if (current_i - 1 >= 0 && village[current_i - 1][current_j] == next) {
                current_i--;
                next++;
                directions += 'U';
            }
            else if (current_i + 1 < n && village[current_i + 1][current_j] == next) {
                current_i++;
                next++;
                directions += 'D';
            }
            else {
                cout << "no";
                return 0;
            }
            if (next == k + 1) {
                cout << "yes" << '\n';
                cout << directions;
                return 0;
            }
        }
    }

    cout << "no";

    return 0;
}