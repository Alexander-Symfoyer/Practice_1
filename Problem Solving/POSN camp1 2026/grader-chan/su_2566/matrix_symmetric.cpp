#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i + 1; j++) {

            if (j == i) matrix[i][j] = 0;
            cin >> matrix[i + 1][j];
            matrix[j][i+1] = matrix[i+1][j]; 

        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }   cout << '\n';
    }
    
}