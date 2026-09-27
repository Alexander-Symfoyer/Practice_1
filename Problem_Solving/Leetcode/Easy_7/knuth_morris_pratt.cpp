#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abcabcabcabc";
    int n = s.size();
    vector<int> lps(n, 0);

    int j = 0;
    for (int i = 1; i < n; i++) {

        while (j > 0 && s[i] != s[j]) {
            j = lps[j-1];
        }

        if (s[i] == s[j]) {
            j++;
            lps[i] = j;
        }

    }

    int pattern = n - lps[n-1];

    return lps[n-1] > 0 && n % pattern == 0;

}