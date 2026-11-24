#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    long long m = n;
    long long x = n;
    long long total_sum = 0;
    int n_size = 0;

    while (m > 0) {
        n_size++;
        m /= 10;
    }

    while (n > 0) {
        long long digit = n % 10;
        long long sum = 1;
        for (int i = 0; i < n_size; i++) {
            sum *= digit;
        }
        total_sum += sum;
        n /= 10;
    }

    if (total_sum == x) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

    return 0;
}