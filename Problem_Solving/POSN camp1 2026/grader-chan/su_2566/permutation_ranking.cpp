#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);        //* O(n^2) (better than O(n!))
    cin.tie(nullptr);

    int n;
    string s;
    cin >> n >> s;

    long long fact[13];
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    bool used[26] = {};
    long long soln = 1;

    for (int i = 0; i < n; i++) {
        int smaller = 0;
        for (char c = 'A'; c < s[i]; c++) {

            if (!used[c - 'A']) {
                smaller++;
            }


        }
        soln += smaller * fact[n - i - 1];
        used[s[i] - 'A'] = true;
    }

    cout << soln;

}