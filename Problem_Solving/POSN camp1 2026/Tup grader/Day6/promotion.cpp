#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    int price = 0;
    while (n >= 4) {
        n -= 4;
        price += (249 * 3);
    }
    price += (249 * n);
    cout << price << '\n';

    return 0;
}