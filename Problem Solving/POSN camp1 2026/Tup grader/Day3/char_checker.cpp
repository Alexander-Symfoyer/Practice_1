#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int capital = 0;
    int small = 0;

    for (int i = 0; i < s.size(); i++) {
        if (islower(s[i])) {
            small++;
        }
        else {
            capital++;
        }
    }

    if (capital == s.size()) {
        cout << "All Capital Letter";
    }
    else if (small == s.size()) {
        cout << "All Small Letter";
    }
    else {
        cout << "Mix";
    }

    return 0;
}