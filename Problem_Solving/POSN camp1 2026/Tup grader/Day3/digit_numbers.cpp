#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x,y;
    cin >> x >> y;
    int z = 0;
    int sum = x + y;
    while (sum > 0) {
        sum /= 10;
        z++;
    }
    cout << z;

    return 0;
}