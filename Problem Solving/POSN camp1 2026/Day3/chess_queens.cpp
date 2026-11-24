#include <bits/stdc++.h>
using namespace std;

bool can_place(int row, int col, vector<string>& board, vector<bool> use_col,
vector<bool>& diag1, vector<bool>& diag2) {

    if (board[row][col] == '*') {
        return 0;
    }
    if (use_col[col]) {
        return 0;
    }
    if (diag1[row - col + 7]) {
        return 0;
    }
    if (diag2[row + col]) {
        return 0;
    }

    return 1;

}

void solve(int row, int &soln, vector<string>& board, vector<bool> use_col,
vector<bool>& diag1, vector<bool>& diag2) {

    if (row == 8) {
        soln++;
        return;
    }

    for (int col = 0; col < 8; col++) {

        if (!can_place(row, col, board, use_col, diag1, diag2)) continue;

        use_col[col] = true;
        diag1[row - col + 7] = true;
        diag2[row + col] = true;

        solve(row + 1, soln, board, use_col, diag1, diag2);

        use_col[col] = false;
        diag1[row - col + 7] = false;
        diag2[row + col] = false;

    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }

    vector<bool> use_col(8, false);
    vector<bool> diag1(15, false);
    vector<bool> diag2(15, false);
    int soln = 0;

    solve(0, soln, board, use_col, diag1, diag2);

    cout << soln << '\n';

}