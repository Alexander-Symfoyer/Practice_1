#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abcd";
    string t = "abcde";

    int ans = 0;
    for (char c : s) {
        ans ^= (c - 'a');
    }
    for (char c : t) {
        ans ^= (c - 'a');
    }

    cout << (char)('a' + ans);

}