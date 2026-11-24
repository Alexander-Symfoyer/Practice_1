#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    string adrian = "ABC";
    string bruno = "BABC";
    string goran = "CCAABB";

    int ad = 0, br = 0, go = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == adrian[i % 3]) {
            ad++;
        }
        if (s[i] == bruno[i % 4]) {
            br++;
        }
        if (s[i] == goran[i % 6]) {
            go++;
        }
    }

    int max_value = max({ad, br, go});
    cout << max_value << '\n';
    if (max_value == ad) {
        cout << "Adrian" << '\n';
    }
    if (max_value == br) {
        cout << "Bruno" << '\n';
    }
    if (max_value == go) {
        cout << "Goran" << '\n';
    }


}