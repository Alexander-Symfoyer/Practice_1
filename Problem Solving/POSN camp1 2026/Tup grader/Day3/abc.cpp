#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,c;
    string s;
    cin >> a >> b >> c;
    cin >> s;

    if (a > 100 || b > 100 || c > 100) return 0;

    vector<int> abc;
    abc.push_back(a);
    abc.push_back(b);
    abc.push_back(c);

    sort(abc.begin(), abc.end());

    for (int i = 0; i < 3; i++) {
        if (s[i] == 'C') {
            cout << abc[2] << " ";
        }
        else if (s[i] == 'B') {
            cout << abc[1] << " ";
        }
        else {
            cout << abc[0] << " ";
        }

    }

    return 0;
}