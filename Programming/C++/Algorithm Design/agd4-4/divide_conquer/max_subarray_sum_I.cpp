#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {                            // O(n^2)
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, -1, 4, 3, -7};
    int n = arr.size();

    vector<int> prefix(n + 1, 0);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }
    //? prefix = {0, 1, 3, 2, 6, 9, 2}

    ll soln = arr[0];
    for (int i = 1; i <= n; i++) {
        ll sum = 0;
        for (int j = i; j <= n; j++) {
            sum = prefix[j] - prefix[i - 1];
            if (sum > soln) {
                soln = sum;
            }
        }
    }
    cout << soln;
}