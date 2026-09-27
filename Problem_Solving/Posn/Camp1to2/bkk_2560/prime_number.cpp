#include <bits/stdc++.h>
using namespace std;

int main() {                            //* O(x * sqrt(x))
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> prime;

    if (n < 3) {
        cout << "";
        return 0;
    }
    
    for (int i = 2; i < n; i++) {
        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
                break;
            }
        }
        if (is_prime) {
            prime.push_back(i);
        }
    }

    for (const int& x : prime) {
        cout << x << '\n';
    }   

}