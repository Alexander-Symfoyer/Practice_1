#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long previous;
    cin >> previous;
    long long moves = 0;
    for (int i = 0; i < n - 1; i++) {
        long long current;
        cin >> current;
        if (previous > current) {
            moves += previous - current;
            previous = current + (previous - current);
        }
        else {
            previous = current;
        }
    }

    cout << moves;

    return 0;
}