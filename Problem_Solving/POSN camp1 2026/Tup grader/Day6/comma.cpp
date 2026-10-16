#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    cin >> s;
    if (s.size() > 1000) return 0;
    string soln;

    bool dot = false;
    int pos;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '.') {
            dot = true;
            pos = i;
        }
    }

    int n = s.size();
    if (dot) {
        n = s.size() - (s.size() - pos - 1) - 1;
        for (int i = 0; i < (s.size() - pos - 1); i++) {
            soln += s[s.size() - i - 1];
        }
        soln += ".";
    }

    int count = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (count != 3) {
            soln += s[i];
            count++;
        }
        else {
            count = 1;
            soln += ",";
            soln += s[i];
        }
    }

    reverse(soln.begin(), soln.end());
    cout << soln << '\n';

    return 0;
}