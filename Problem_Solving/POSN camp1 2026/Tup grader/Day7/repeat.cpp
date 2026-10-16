#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s;
    cin >> s;
    int max_count = -1;
    int count = 0;
    string max_s = "";
    string current = "";
    for (int i = 0; i < s.size(); i++) {
        if (i == 0) {
            count++;
            current += s[i];
        }
        if (s[i-1] == s[i]) {
            count++;
            current += s[i];
        }
        else {
            if (current.size() > max_s.size()) {
                max_s = current;
            }
            current = s[i];
            count = 0;
        }
        max_count = max(count, max_count);
    }

    cout << max_s << '\n';
    cout << max_count << '\n';

    return 0;
}