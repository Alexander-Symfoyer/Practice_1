#include <iostream>
using namespace std;

const int max_row = 100;
const int max_col = 50;

int main() {
    int matrix[max_row][max_col] = {0};
    int n;
    int m;
    cout << "Enter row : "; cin >> n;
    cout << "Enter col : "; cin >> m;
    if (n > max_row || m > max_col) {
        cout << "Size too large" << endl;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter " << m << " values of row " << i << ": " << endl;
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }
}