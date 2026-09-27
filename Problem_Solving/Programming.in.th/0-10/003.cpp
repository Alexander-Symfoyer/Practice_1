#include <iostream>
#include <vector>
using namespace std;

int main() {

    int m,n;
    cin >> m >> n;

    vector<vector<long long>> a(m, vector<long long>(n));
    vector<vector<long long>> b(m, vector<long long>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] + b[i][j];
            if (j != n - 1) cout << " ";
        }
        cout << '\n';
    }

    return 0;

}