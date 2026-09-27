#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int soln = 0;
    int i = 1;

    while (n > 0) {
        n -= i;
        i++;
    }

    if (n == 0) {
        cout << i - 1;
    }
    else {
        cout << i - 2;
    }

}