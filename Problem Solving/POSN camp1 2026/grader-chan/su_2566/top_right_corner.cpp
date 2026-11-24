#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);            //* O(sqrt(n))
    cin.tie(nullptr);

    long long n;
    cin >> n;

    long long side = 1;

    while (side * side < n) {
        side += 2;
    }

    long long corner = side * side - side + 1;

    if (n == corner - 2) {
        cout << "Cannot find top-right corner.";
    }
    else if (n >= corner - 1) {
        cout << min(n, corner);
    }
    else {
        side -= 2;
        long long top_right = side * side - side + 1;
        cout << top_right;
    }

}