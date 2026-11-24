#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<char> s(5);
    unordered_map<char, int> count;

    for (int i = 0; i < 5; i++) {
        cin >> s[i];
        count[s[i]]++;
    }

    bool perfect = true;
    bool carry = false;

    for (int i = 0; i < 5; i++) {
        if (count.count(s[i]) && count[s[i]] > 1) {
            perfect = false;
        }
        if (s[i] == 'C') {
            carry = true;
        }
    }

    if (perfect && carry) cout << "Perfect";
    else cout << "Not perfect";

    return 0;
}