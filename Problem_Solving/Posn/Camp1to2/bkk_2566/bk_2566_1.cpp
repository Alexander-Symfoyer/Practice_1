#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a,b,x;
    cin >> a >> b >> x;

    int digit = 0;
    int product = a * b;
    int temp = product;
    while (temp > 0) {
        temp /= 10;
        digit++;
    }

    if (x > digit) {
        cout << "_";
    }
    else {
        for (int i = 0; i < digit - x; i++) {
            product /= 10;
        }
        cout << product % 10;
    }

}