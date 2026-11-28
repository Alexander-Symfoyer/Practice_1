#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "leetcode";
    unordered_map<char, int> freq;

    for (int i = 0; i < s.size(); i++) {
        freq[s[i]]++;
    }

    for (int j = 0; j < s.size(); j++) {
        if (freq[s[j]] == 1) {
            cout << j;
            return 0;
        }
    }

}