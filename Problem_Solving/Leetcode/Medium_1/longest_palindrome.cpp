#include <bits/stdc++.h>
using namespace std;

void expand(int left, int right, int& start, int& max_len, const int& n, const string& s) {

    while (left >= 0 && right < n && s[left] == s[right]) {

        left--;
        right++;

    }

    left++;
    right--;

    if (left > right) {
        return;
    }

    int len = right - left + 1;
    if (len > max_len) {
        max_len = len;
        start = left;
    }

}

int main() {                        //* O(n^2)

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abcbac";

    int start = 0;
    int max_len = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {

        expand(i, i, start, max_len, n, s);
        expand(i, i+ 1, start, max_len, n, s);

    }

    cout << s.substr(start, max_len);       //* Parameter (pos, count)

}