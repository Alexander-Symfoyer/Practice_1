#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int count = 1;
    int longest = 1;
    for (int i = 0; i < n; i++) {
        count =  (s[i] == s[i + 1]) ? count + 1 : 1;
        longest = max(longest, count);
    }

    cout << longest << '\n';

    return 0;
}