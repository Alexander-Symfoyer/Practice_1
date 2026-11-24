#include <bits/stdc++.h>
using namespace std;
                                    //* Total O(n* (sqrt(n))
bool is_prime(const int& x) {       //* O(sqrt(x))

    if (x < 2) return false;

    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }

    return true;

}

int count_primes(const int& n) {

    int count = 0;
    for (int i = 2; i < n; i++) {
        if (is_prime(i)) count++;
    }

    return count;

}

int main() {
    int n;
    cin >> n;
    cout << count_primes(n);
}

