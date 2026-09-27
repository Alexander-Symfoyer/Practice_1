#include <bits/stdc++.h>
using namespace std;
int main() {                        //* O(n^2)

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "hiragoshinji";
    int numRows = 5;

    if (numRows == 1) {
        cout << s;
        return 0;
    }

    vector<vector<char>> grid(numRows, vector<char>(s.size(), '\0'));

    int i = 0; 
    int j = 0;
    int k = 0;

    while (k < s.size()) {

        while (i < numRows && k < s.size()) {
            grid[i][j] = s[k];
            i++;
            k++;
        }

        i--;
        i--;
        j++;

        while (i >= 0 && k < s.size()) {
            grid[i][j] = s[k];
            j++;
            i--;
            k++;
        }

        i++;
        i++;

    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < s.size(); j++) {
            if (grid[i][j] != '\0') {
                cout << grid[i][j];
            }
        }
    }

}