#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());
    long long missing = 1;

    for (int i = 0; i < n; i++) {
        if (coins[i] <= missing) {
            missing += coins[i];
        }
        else break;
    }

    cout << missing << '\n';

    return 0;
}