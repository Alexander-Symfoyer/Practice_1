#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll get_sum(vector<int> prefix, int a, int b) {
    return prefix[b] - prefix[a-1];
}

int cal(vector<int> arr, int start, int stop, vector<int> prefix) {
    if (start == stop) {
        return arr[start];
    }
    int m = (start + stop) / 2;
    ll r1 = cal(arr, start, m, prefix);
    ll r2 = cal(arr, m + 1, stop, prefix);
    
    ll max_sum_left = get_sum(prefix, m, m);        //* maximum suffix sum
    for (int i = start; i <= m - 1; i++) {
        max_sum_left = max(max_sum_left, get_sum(prefix, i , m));
    }

    ll max_sum_right = get_sum(prefix, m + 1, m + 1);   //* maximum prefix sum
    for (int j = m + 2; j <= stop; j++) {
        max_sum_right = max(max_sum_right, get_sum(prefix, m + 1, j));
    }

    ll r3 = max_sum_right + max_sum_left;

    return max({r1, r2, r3});

}

int main() {
    ios::sync_with_stdio(false);        //* O (n log n)
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