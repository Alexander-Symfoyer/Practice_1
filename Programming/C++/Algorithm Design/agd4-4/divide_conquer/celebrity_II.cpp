#include <bits/stdc++.h>
using namespace std;
using ll = long long;   //* O(n log n)

int find_celeb(vector<vector<int>>& arr, int start, int stop) {

    if (start == stop) {
        return start;
    }
    int m = (start + stop) / 2;

    int r1 = find_celeb(arr, start, m);
    if (r1 != -1) {
        for (int j = m+1; j <= stop; j++) {
            if(!arr[j][r1] || arr[r1][j]) {
                r1 = -1;
                break;
            }
        }
    }
    if (r1 != -1) return r1;

    int r2 = find_celeb(arr, m+1, stop);
    if (r2 != -1) {
        for (int j = 0; j < m; j++) {
            if (!arr[j][r2] || arr[r2][j]) {
                r2 = -1;
                break;
            }
        }
    }
    if (r2 != -1) return r2;

    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << find_celeb(arr, 0, n-1);
}