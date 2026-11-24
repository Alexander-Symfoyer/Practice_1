#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());
    int gondola = 0;
    int i = 0, j = n - 1;
    while (i < j) {

        if (weights[i] + weights[j] > k) {
            gondola++;
            j--;
        }
        else {
            i++;
            j--;
            gondola++;
        }

    }

    if (i == j) gondola++;
    cout << gondola << '\n';

    return 0;
}