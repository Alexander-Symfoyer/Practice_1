#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    sort(s.begin(), s.end());
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i] == s[i-1]) {
            continue;
        }
        else {
            cout << s[i] << ' ';
        }
    }

}