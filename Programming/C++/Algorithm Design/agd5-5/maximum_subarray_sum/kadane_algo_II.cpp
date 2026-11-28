#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* Top-down approach

int max_suffix(
    vector<int>& arr, int stop, 
    vector<int>& table, vector<bool>& done
) {
    if (stop == 0) {
        table[stop] = arr[0];
        done[stop] = 1;
        return table[stop];
    }

    if (done[stop]) return table[stop];     //! Memoization
    table[stop] = max(
        arr[stop],
        arr[stop] + max_suffix(arr, stop-1, table, done)
    );

    done[stop] = 1;          //! Memoization
    return table[stop];

}

int mss(
    vector<int>& arr, int stop, 
    vector<int>& table, vector<bool>& done
) {
    if (stop == 0) return arr[0];

    int r1 = mss(arr, stop-1, table, done);     //* mss does not include arr[stop]
    int r2 = arr[stop];                         //* mss contains only arr[stop]
    int r3 = max_suffix(
        arr, stop-1, table, done) + arr[stop    //* mss ends at arr[stop]
        ];                                      //* extends the best suffix of the prev elements

    return max({r1, r2, r3});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> table(n+1);
    vector<bool> done(n+1, 0);

    cout << mss(arr, n-1, table, done);
}