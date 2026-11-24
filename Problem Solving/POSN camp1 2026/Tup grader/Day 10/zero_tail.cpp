#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, m;
    cin >> n >> m;

    long long divisor_n = 5;
    long long tail_n = 0;
    while (n >= divisor_n) {
        tail_n += (n / divisor_n);
        divisor_n *= 5;
    }

    long long tail_m = 0;
    long long divisor_m = 5;
    while (m >= divisor_m) {
        tail_m += (m / divisor_m);
        divisor_m *= 5;
    }

    cout << tail_n - tail_m << '\n';
    
    return 0;
}