#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;

void backtrack(
    string current, int open, int close
) {

    if (open == n && close == n) {
        ans.push_back(current);
        return;
    }

    if (open < n) {
        backtrack(current + "(", open + 1, close);
    }
    if (close < open) {
        backtrack(current+ ")", open, close + 1);
    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    backtrack("", 0, 0);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }   cout << '\n';

}