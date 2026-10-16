#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int l, n;
    cin >> l >> n;

    int orange = 1;
    int oranges = orange * orange;
    while (n >= oranges) {
        n -= (oranges);
        l--;
        orange++;
        oranges = orange * orange;
    }

    cout << l << '\n';

}