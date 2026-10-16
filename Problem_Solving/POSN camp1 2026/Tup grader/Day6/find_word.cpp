#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string main, sub;
    cin >> main >> sub;
    int n = sub.size();
    int m = main.size();
    bool found = false;
    for (int i = 0; i < m; i++) {
        if (i != m - n && main.substr(i, n) == sub) {
            cout << i << " ";
            found = true;
        }
    }
    if (!found) cout << "not found" << '\n';

}