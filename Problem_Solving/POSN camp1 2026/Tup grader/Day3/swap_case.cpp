#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            }
            else {
                s[i] = tolower(s[i]);
            }
        }
    }

    cout << s;

    return 0;
}