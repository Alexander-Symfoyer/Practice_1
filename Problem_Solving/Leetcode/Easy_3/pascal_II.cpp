#include <iostream>
#include <vector>
using namespace std;
int main() {

    int rowIndex = 4;

    vector<int> row = {1};

    for (int i = 0; i < rowIndex; i++) {

        vector<int> newrow;
        newrow.push_back(1);

        for (int j = 1; j < row.size(); j++) {
            newrow.push_back(row[j - 1] + row[j]);
        }

        newrow.push_back(1);
        row = newrow;

    }

    for (int x : row) {
        cout << x << " ";
    }
    
}