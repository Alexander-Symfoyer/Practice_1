#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board;
    
    vector<unordered_set<char>> rows(9);
    vector<unordered_set<char>> cols(9);
    vector<unordered_set<char>> boxes(9);

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            char num = board[r][c];
            if (num == '.') continue;
            int box = (r / 3) * 3 + (c / 3);
            if (rows[r].count(num) || cols[c].count(num) || boxes[box].count(num)) {
                cout << "False";
                return 0;
            }
            else {
                rows[r].insert(num);
                cols[c].insert(num);
                boxes[box].insert(num);
            }
        }
    }

    cout << "True";

}