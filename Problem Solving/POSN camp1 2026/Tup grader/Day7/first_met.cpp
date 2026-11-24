#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x,y;
    cin >> x >> y;
    bool is_x = false;
    bool is_y = false;
    while (true) {
        int n;
        cin >> n;
        if (n < 0) {
            cout << n;
            break;
        }
        if (n % x == 0) is_x = true;
        if (n % y == 0) is_y = true;
        if (is_x && is_y) {
            cout << n << '\n';
            cout << 2;
            break;
        }
        else if (is_x) {
            cout << n << '\n';
            cout << 0;
            break;
        }
        else if (is_y) {
            cout << n << '\n';
            cout << 1;
            break;
        }
    }

    return 0;
}