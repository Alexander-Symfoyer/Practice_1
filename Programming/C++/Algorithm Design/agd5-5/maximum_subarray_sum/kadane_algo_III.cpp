#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Bottom-up approach
//* O(n) && O(1) (1D)

ll mss(vector<ll>& arr) {
    ll suf = arr[0];
    ll mss = arr[0];
    for (int i = 1; i < arr.size(); i++) {
        suf = max(arr[i], suf + arr[i]);
        //* 1 start a new subarray at arr[i]
        //* 2 extend the previous maximum suffix by arr[i]

        mss = max(mss, suf);
        //* update the overall mss
    }
    return mss;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << mss(arr);
}