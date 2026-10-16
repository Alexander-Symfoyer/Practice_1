#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {

    int z = x % y;
    if (z == 0) return y;
    else return (gcd(y,z));

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y;
    cin >> x >> y;

    cout << gcd(x,y);

    return 0;
}