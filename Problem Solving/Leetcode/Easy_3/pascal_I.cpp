#include <iostream>
#include <vector>
using namespace std;
int main() {

    int numRows = 10;
    vector<vector<int>> ans;

    for (int i = 0; i < numRows; i++) {
        vector<int> row;
        for (int j = 0; j < i + 1; j++) {

            if (j == 0 || j == i) {
                row.push_back(1);
            }

            else {
                row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }

        }
        ans.push_back(row);
    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j];
        }
        cout << '\n';
    }

}