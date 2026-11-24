#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    long long previous;
    long long max_sum = LLONG_MIN;
    long long current_sum = LLONG_MIN;
    cin >> n;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (i == 0) {
            previous = x;
            max_sum = x;
            continue;
        }
        else {
            current_sum = max(x, previous + x);
        }
        previous = current_sum;
        max_sum = max(current_sum, max_sum);
    }

    cout << max_sum << '\n';

    return 0;
}