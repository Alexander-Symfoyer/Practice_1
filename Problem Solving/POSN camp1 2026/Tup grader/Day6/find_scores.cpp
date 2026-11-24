#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    for (int i = 0; i < n; i++) {
        if (nums[i] == k) {
            cout << "Found " << nums[i] << " index " << i;
            return 0;
        }
    }

    cout << "Not found";

}