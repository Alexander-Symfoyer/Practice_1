#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Celebrity = 0 in entire row and 1 in entire column
//! O(n)

int find_celeb(vector<vector<int>>& arr, int start, int stop) {

    if (start == stop) {
        for (int j = 0; j <= stop; j++) {
            if (arr[start][j]) return -1;
            if (j != start && !arr[j][start]) return -1;
        }
        return start;
    }

    if (arr[start][stop]) return find_celeb(arr, start + 1, stop);
    //* if = 1 mean start can't use
    //* start knows someone

    else return find_celeb(arr, start, stop - 1);
    //* if = 0 mean stop can't use
    //* someone don't know stop

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