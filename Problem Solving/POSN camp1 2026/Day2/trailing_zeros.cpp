#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long tail = 0;
    long long divisor = 5;
    while (n >= divisor) {
        tail += n / divisor;
        divisor *= 5;
    }

    cout << tail;

    return 0;
}