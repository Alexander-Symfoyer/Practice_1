#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;

    if (n > 100000 || n < 0 || m > 26 || m < 0) return 0;

    unordered_set<char> target;
    
    string s;
    cin >> s;
    for (int i = 0; i < m; i++) {
        if (target.count(s[i])) return 0;
        target.insert(s[i]);
    }


    vector<string> soln(3, "");
    for (int i = 0; i < 3; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (!target.count(s[j])) {
                soln[i] += s[j];
            }
        }
    }

    for (const string& s : soln) {
        if (s == "") cout << '-' << '\n';
        else cout << s << '\n';
    }

    return 0;
}