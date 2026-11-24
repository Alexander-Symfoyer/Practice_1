#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;

    long long sum = 0;
    long long max_value = LLONG_MIN;
    long long min_value = LLONG_MAX;

    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;

        max_value = max(max_value, x);
        min_value = min(min_value, x);
        sum += x;
    }

    long long range = max_value - min_value;
    long double mean = (long double)sum / n;

    cout << range << " ";
    cout << fixed << setprecision(2) << mean << '\n';

    return 0;

}