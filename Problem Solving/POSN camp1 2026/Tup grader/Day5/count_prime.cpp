#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int count = 0;
   
    vector<bool> is_prime(b + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = a; i <= b; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= b; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = a; i <= b; i++) {
        if (is_prime[i]) count++;
    }

    cout << count;

}