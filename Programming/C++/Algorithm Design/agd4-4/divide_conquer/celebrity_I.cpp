#include <bits/stdc++.h>
using namespace std;
using ll = long long;   

int find_celeb(vector<vector<int>>& arr, const int& n) {

    for (int i = 0; i < n; i++) {
        bool celeb = true;
        for (int j = 0; j < n; j++) {   //* Check if i knows nobody
            if (arr[i][j]) {
                celeb = false;
                break;
            }
        }

        if (!celeb) continue;
        for (int j = 0; j < n; j++) {   //* Check if everyone knows i
            if (i != j && !arr[j][i]) {
                celeb = false;
                break;
            }
        }

        if (celeb) return i;

    }
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

    cout << find_celeb(arr, n);
}