#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> sieve(100005, 0);
    for (int i = 1; i <= 50000; i++) {
        for (int j = i * 2; j < 100000; j += i) {
            
        }
    }

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int sum = 0;

        
        
        if (sum == x) {
            cout << "P" << '\n';
        }
        else if (sum < x) {
            cout << "D" << '\n';
        }
        else if (sum > x) {
            cout << "A" << '\n';
        }
    }

    return 0;
}