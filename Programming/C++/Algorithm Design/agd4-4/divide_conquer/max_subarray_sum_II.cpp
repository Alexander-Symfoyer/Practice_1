#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int cal(vector<int> arr, int start, int stop, vector<int> prefix) {
    if (start == stop) {
        return arr[start];
    }
    int m = (start + stop) / 2;
    int r1 = cal(arr, start, m, prefix);
    int r2 = cal(arr, m + 1, stop, prefix);
    int r3 = arr[start];

    for (int i = start; i <= m; i++) {
        for (int j = m + 1; j <= stop; j++) {
            ll sum =  prefix[j] - prefix[i - 1];
            if (sum > r3) {
                r3 = sum;
            }
        }
    }

    return max({r1, r2, r3});

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, -1, 4, 3, -7};
    int n = arr.size();

    vector<int> prefix(n + 1, 0);
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + arr[i-1];
    }

    cout << cal(arr, 0, n - 1, prefix);

}