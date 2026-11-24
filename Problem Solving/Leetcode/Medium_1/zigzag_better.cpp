#include <bits/stdc++.h>
using namespace std;
int main() {                        //* O(n)

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "kurosakiichigo";
    int numRows = 3;

    vector<string> rows(numRows);

    int row = 0;
    int k = 0;
    int direction = 1;

    for (const char& c : s) {

        rows[row] += c;

        if (row == numRows - 1) {
            direction = -1;
        }
        else if (row == 0) {
            direction = 1;
        }
        
        row += direction;

    }

    for (int i = 0; i < numRows; i++) {
        cout << rows[i];
    }

}