#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* O(2^n)

int fibo(int n) {
    if (n == 1 || n == 0) return n;
    if (n >= 2) return fibo(n-1) + fibo(n-2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << fibo(n);

}