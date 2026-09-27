#include <bits/stdc++.h>
using namespace std;            //! O(9 ^ 81)

bool is_valid(int r, int c, char num, vector<vector<char>>& board) {        

    for (int i = 0; i < 9; i++) {       //* Check row
        if (board[r][i] == num) {
            return false;
        }
    }

    for (int i = 0; i < 9; i++) {       //* Check column
        if (board[i][c] == num) {
            return false;
        } 
    }

    int start_row = (r / 3) * 3;        //* Find top-left corner of 3x3 box (start)
    int start_col = (c / 3) * 3;
    for (int i = start_row; i < start_row + 3; i++) {       //*  Check 3x3 box (current)
        for (int j = start_col; j < start_col + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }

    return true;

}

bool solve(vector<vector<char>>& board) {

    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {

            if (board[r][c] == '.') {
                for (char num = '1'; num <= '9'; num++) {   //* Try digits 1-9

                    if (is_valid(r,c, num, board)) {       //* Check if valid
                        board[r][c] = num;          //* Place the number

                        if (solve(board)) {         //* Solve the rest
                            return true;
                        }

                        board[r][c] = '.';          //* Back track
                    }

                }
                return false;       //* No number worked
            }
        }
    }

    return true;        //* No empty cells remain

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<char>> board;

    solve(board);

}