#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    double sum = 0;
    for (int i = 0; i < n; i++) {
        double weight, price;
        cin >> weight >> price;
        sum += (weight * price);
    }

    if (sum <= 400) {
        sum *= 0.95;
    }
    else {
        if (sum * 0.1 > 200) {
            sum -= 200;
        }
        else {
            sum *= 0.90;
        }
    }

    cout << fixed << setprecision(2) << sum  << '\n';

}