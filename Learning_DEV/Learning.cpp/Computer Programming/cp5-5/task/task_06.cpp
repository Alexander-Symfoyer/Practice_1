#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> grid = {
        {1,43,13}, {32,83,10}, {31,82,01}
    };
    
    int n = grid.size();
    int m = grid[0].size();

    long long sum = INT_MIN;
    int max_val = 0;
    int max_col;
    int max_row;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            int x = grid[i][j];
            sum += x;
            if (x > max_val) {
                max_val = x;
                max_col = j;
                max_row = i;
            }

        }
    }

    cout << sum << " " << max_val 
    << " " << max_col << " " << max_row << '\n';

}

//INT_MIN = -2147483648
//INT_MAX =  2147483647
