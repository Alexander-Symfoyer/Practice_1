#include <bits/stdc++.h>
using namespace std;
int main () {                       //* O(n)

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    vector<int> ans(n + 1);
    int offset = 1;
    ans[0] = 0;
    for (int i = 1; i <= n; i++) {

        if (i == offset * 2) {
            offset *= 2;
        }

        ans[i] = ans[i - offset] + 1;

    }

    for (const int& x : ans) {
        cout << x << " ";
    }   cout << '\n';

}