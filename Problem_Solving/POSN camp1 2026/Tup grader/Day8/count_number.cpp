#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int count = 0;
    int k;
    cin >> k;
    while (true) {
        int n;
        cin >> n;
        if (n == 0) {
            if (count == 0) cout << "None";
            else cout << count;
            return 0;
        }
        if (n == k) count++;
    }

    return 0;
}