#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, l;
    cin >> n >> l;
    vector<int> chick(n);
    for (int i = 0; i < n; i++) {
        cin >> chick[i];
    }

    vector<int> prefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        prefix[i+1] = prefix[i] + chick[i];
    }

    unordered_map<int, int> freq;
    long long count = 0;

    for (int r = l; r <= n; r++) {
        freq[prefix[r-l]]++;
        count += freq[prefix[r]];
    }

    cout << count << '\n';

    return 0;
}