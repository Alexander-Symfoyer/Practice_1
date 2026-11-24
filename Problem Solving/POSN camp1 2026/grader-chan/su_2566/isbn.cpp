#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sum = 0;

    for (int i = 10; i > 1; i--) {
        int x;
        cin >> x;
        sum += (x * i);
    }

    int soln = (11 - (sum % 11)) % 11;
    cout << soln;

}