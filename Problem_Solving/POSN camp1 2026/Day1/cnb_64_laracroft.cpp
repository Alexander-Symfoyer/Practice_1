#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, max_weight;
    cin >> n >> max_weight;
    vector<int> weights(n);
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    vector<long long> dp(max_weight + 1);



}