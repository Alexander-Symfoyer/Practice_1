#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cin >> k;

    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + (n - k));
    reverse(nums.begin() + (n - k), nums.end());

    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }

    return 0;
}