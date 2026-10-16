#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    int z = x % y;
    if (z == 0) return y;
    else return gcd(y, z);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    if (x <= y) return 0;
    if (x < 5 || x > 1000000) return 0;
    if (y < 3 || y > 1000000) return 0;
    int z = gcd(x, y);
    cout << x / z << " " << y / z;

    return 0;
}