#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    int median;
    sort(v.begin(), v.end());
    if (v.size() % 2 == 0) {
        median = v[(v.size() / 2) - 1];
    }
    else {
        median = v[(v.size() / 2 + 1) - 1];
    }

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += (abs(median - v[i]));
    }

    cout << total << '\n';

    return 0;
}