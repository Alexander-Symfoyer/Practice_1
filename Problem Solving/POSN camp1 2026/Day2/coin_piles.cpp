#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int x,y;
        cin >> x >> y;

        if ((x + y) % 3 == 0) {
            if (max(x,y) > min(x,y) * 2) {
                cout << "NO" << '\n';
            }
            else {
                cout << "YES" << '\n';
            }
        }
        else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}