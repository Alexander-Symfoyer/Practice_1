#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int n, a, b;
        cin >> n >> a >> b;

        if (a + b > n || ((a == 0 & b != 0) || (a != 0 && b == 0)) ) {
            cout << "NO" << '\n';
            continue;
        }
        if (a + b == 0) {
            cout << "YES" << '\n';
            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }   cout << '\n';

            for (int i = 1; i <= n; i++) {
                cout << i << " ";
            }   cout << '\n';
        }
        else {
            cout << "YES" << '\n';
            int draw = n - a - b;
            for (int i = 1; i <= draw; i++) {
                cout << i << " ";
            }
            for (int i = draw + 1; i <= draw + a; i++) {
                cout << i << " ";
            }
            for (int i = draw + a + 1; i <= n; i++) {
                cout << i << " ";
            }   cout << '\n';

            for (int i = 1; i <= draw; i++) {
                cout << i << " ";
            }
            for (int i = draw + a + 1; i <= n; i++) {
                cout << i << " ";
            }
            for (int i = draw + 1; i <= draw + a; i++) {
                cout << i << " ";
            }   cout << '\n';
        }

    }

}