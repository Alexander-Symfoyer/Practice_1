#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> soln;

    for (int i = n - 1; i >= 2; i--) {

        bool is_prime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                is_prime = false;
            }
        }
        if (is_prime) {
            soln.push_back(i);
        }
        if (soln.size() == 5) {
            break;
        }

    }

    for (int i = 4; i >= 0; i--) {
        cout << soln[i] << " ";
    }   cout << '\n';

}