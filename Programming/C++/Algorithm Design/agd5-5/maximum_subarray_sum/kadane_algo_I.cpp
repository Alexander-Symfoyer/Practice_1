#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* O(n^2)

int max_suffix(vector<int>& arr, int stop) {
    if (stop == 0) return arr[0];
    return max(arr[stop], arr[stop] + max_suffix(arr, stop-1));
    //* s(i) = max(ai, ai + s(i-1))
}

int mss(vector<int>& arr, int stop) {
    if (stop == 0) return arr[0];
    int r1 = mss(arr, stop-1);
    int r2 = arr[stop];
    int r3 = max_suffix(arr, stop-1) + arr[stop];
    return max({r1, r2, r3});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr = {1, 2, 3};
    cout << mss(arr, n-1);
}