#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int n;
    cin >> n;

    for (int i = 0; i < s.size(); i++) {
        if (isalpha(s[i])) {
            if (islower(s[i])) {
                int value = ((s[i] - 'a') + n) % 26;
                s[i] = 'a' + value;
            }
            else if (isupper(s[i])) {
                int value = ((s[i] - 'A') + n) % 26;
                s[i] = 'A' + value;
            }
        }
    }
    cout << s;

    return 0;
}