#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (k == nums[i]) {
            count++;
        }
    }

    reverse(nums.begin(), nums.end());
    for (const int& i : nums) {
        cout << i << " ";
    }   cout << '\n';

    cout << count;

    return 0;
}