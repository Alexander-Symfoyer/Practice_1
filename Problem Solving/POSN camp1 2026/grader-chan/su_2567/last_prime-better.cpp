#include <bits/stdc++.h>
using namespace std;

int main() {                            //* O(n log log n)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<bool> is_prime(n + 1, true);
    is_prime[0] = is_prime[1] = false;


    for (int p = 2; p * p <= n; p++) {
        if (!is_prime[p]) continue;

        for (int j = p * p; j <= n; j += p) {
            is_prime[j] = false;
        }
    }

    vector<int> soln;

    for (int i = n - 1; i * i >= 2; i--) {
        if (is_prime[i]) {
            soln.push_back(i);
        }
        if (soln.size() == 5) break;
    }

    reverse(soln.begin(), soln.end());
    for (const int& x : soln) {
        cout << x << " ";
    }   cout << '\n';

}