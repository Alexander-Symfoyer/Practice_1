#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;
    int count = 0;
    vector<int> chick(n);
    for (int i = 0; i < n; i++) {
        cin >> chick[i];
    }

    for (int k = l; k <= n; k++) {
        for (int i = 0; i + k <= n; i++) {
            int sum = 0;
            for (int j = i; j < (i + k); j++) {
                sum += chick[j];
            }
            if (sum == 0) count++;
        }
    }

    cout << count << '\n';

    return 0;
}