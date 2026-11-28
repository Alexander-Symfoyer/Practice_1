#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {                        //* O(log n)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, n;      //? a^n 
    ll soln = 1;
    cin >> a >> n;

    while (n > 0) {
        if (n % 2 == 1) {
            soln *= a;
        }
        a *= a;
        n /= 2;
    }

    cout << soln;
}
// a^x * a^x Even
// a^x * a^x * a Odd