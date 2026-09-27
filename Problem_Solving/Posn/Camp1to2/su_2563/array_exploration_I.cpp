#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int row, col, k;
    cin >> row >> col;
    vector<vector<int>> grid(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            int x; 
            cin >> x;
            grid[i][j] = x;
        }
    }
    
    cin >> k;

    vector<int> target = {0,0,0,0};

    for (int i = 0; i < k; i++) {

        int x,y;
        cin >> x >> y;
        
        if (x > row || y > col || x < 1 || y < 1) continue;

        int value = grid[x - 1][y - 1];

        if (value == 0) {
            target[2]++;
            continue;
        }
        if (value > 0) {
            target[0]++;
        }
        else {
            target[1]++;
        }
        if (value % 2 == 0) {
            target[2]++;
        }
        else {
            target[3]++;
        }

    }

    for (const int& x : target) {
        cout << x << " ";
    }   cout << '\n';

}