#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        long long j;
        cin >> j;
        nums[i] = j;
    }

    long long range;
    double mean = 0;

    long long max_value = LLONG_MIN;
    long long min_value = LLONG_MAX;

    for (const long long& x : nums) {
        max_value = max(max_value, x);
        min_value = min(min_value, x);
        mean += x;
    }

    cout << max_value - min_value << " ";
    cout << fixed << setprecision(2) <<  mean / n << '\n';

}