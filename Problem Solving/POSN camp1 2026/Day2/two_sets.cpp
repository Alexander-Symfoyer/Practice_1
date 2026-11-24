#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n % 4 == 1 || n % 4 == 2) {
        cout << "NO" << '\n';
    }
    else {
        cout << "YES" << '\n';
        if (n % 4 == 0) {
            cout << n / 2 << '\n';

            for (int i = 1; i <= n;) {
                if (i % 2 == 1) {
                    cout << i << " ";
                    i += 3;
                }
                else {
                    cout << i << " ";
                    i++;
                }
            }
            cout << '\n';

            cout << n / 2 << '\n';

            for (int i = 2; i <= n;) {
                if (i % 2 == 0) {
                    cout << i << " ";
                    i++;
                }
                else {
                    cout << i << " ";
                    i += 3;
                }
            }
            cout << '\n';
        }
        else {
            cout << n / 2 << '\n';

            for (int i = 3; i <= n;) {
                if (i % 2 == 1) {
                    cout << i << " ";
                    i++;
                }
                else {
                    cout << i << " ";
                    i += 3;
                }
            }
            cout << '\n';

            cout << n / 2 + 1 << '\n';

            for (int i = 1; i <= n;) {
                if (i % 2 == 1) {
                    cout << i << " ";
                    i++;
                }
                else {
                    cout << i << " ";
                    i += 3;
                }
            }
        }
    }

    return 0;
}