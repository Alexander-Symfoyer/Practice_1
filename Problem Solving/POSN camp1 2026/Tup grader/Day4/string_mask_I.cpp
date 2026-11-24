#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    char c;
    cin >> c;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == c) {
            s[i] = '#';
        }
    }

    cout << s;

    return 0;
}