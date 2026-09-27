#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1, s2;
    cin >> s1 >> s2;

    bool found[256] = {};
    bool printed[256] = {};

    for (int i = 0; i < s1.size(); i++) {
        found[s1[i]] = true;
    }

    for (int i = 0; i < s2.size(); i++) {
        if (found[s2[i]] == true && printed[s2[i]] == false) {
            cout << char(s2[i]) << ' ';
            printed[s2[i]] = true;
        }
    }

}