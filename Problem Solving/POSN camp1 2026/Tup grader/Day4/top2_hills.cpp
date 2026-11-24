#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n <= 1 || n >= 100) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    cout << nums[nums.size() - 1] << '\n';
    int i = 2;
    while (nums[nums.size() - 1] == nums[nums.size() - i]) {
        i++;
    }
    cout << nums[nums.size() - i] << '\n';

    return 0;
}