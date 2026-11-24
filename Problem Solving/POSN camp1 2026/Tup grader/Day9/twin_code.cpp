#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s, ss;
    cin >> s >> ss;
    int count = 0;
    bool found = true;
    for (int i = 0; i < n; i++) {
        if ((s[i] - '0') + (ss[i] - '0') != 9) {
            found = false;
            count++;
        }
    }

    if (found) {
        cout << "YES";
    }
    else {
        cout << "NO" << " " << count;
    }

    return 0;
}