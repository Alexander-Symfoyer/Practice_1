#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s;
    getline(cin, s);

    string soln;
    bool is_palin = true;

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                soln += tolower(s[i]);
            }
            else {
                soln += s[i];
            }
        }
    }

    string sol = soln;
    reverse(soln.begin(), soln.end());
    if (soln == sol) {
        cout << soln.substr(0, soln.size() / 2);
    }
    else {
        cout << '-';
    }

}