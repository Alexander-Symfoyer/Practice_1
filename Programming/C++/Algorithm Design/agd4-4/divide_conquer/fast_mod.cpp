#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {                        //* O(log n)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, n, k;      //? a^n % k
    ll soln = 1;
    cin >> a >> n >> k;
    a %= k;

    while (n > 0) {
        if (n % 2 == 1) {
            soln = (soln * a) % k;
        }
        a = (a * a) % k;
        n /= 2;
    }

    cout << soln;
}
// a^x * a^x Even
// a^x * a^x * a Odd