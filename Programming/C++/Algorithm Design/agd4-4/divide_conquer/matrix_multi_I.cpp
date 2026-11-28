#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> v1 = {{2, 1}, {1, 2}};
    vector<vector<int>> v2 = {{3, 2}, {2, 3}};
    int n = 2;
    vector<vector<int>> soln(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll sum = 0;
            for (int k = 0; k < n; k++) {
                sum += v1[i][k] * v2[k][j];
            }
            soln[i][j] = sum;
        }
    }
}