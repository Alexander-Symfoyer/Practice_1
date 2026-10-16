#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        bool is_prime = true;
        for (int i = 2; i <= (max(a,b) / 2) + 1; i++) {
            if (a % i == 0 && b % i == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            cout << "Y" << '\n';
        }
        else {
            cout << "N" << '\n';
        }
    }
}