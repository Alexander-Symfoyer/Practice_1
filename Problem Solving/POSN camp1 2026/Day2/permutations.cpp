#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << '\n';
        return 0;
    }

    int even = 2;
    int odd = 1;
    while (even <= n) {
        cout << even << " ";
        even += 2;
    }
    while (odd <= n) {
        cout << odd << " ";
        odd += 2;
    }

    cout << '\n';

    return 0;
}