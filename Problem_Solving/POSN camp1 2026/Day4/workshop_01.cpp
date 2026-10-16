#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort(nums.begin(), nums.end());
    cout << nums[0] << nums[1] << nums[2] << '\n';

    return 0;
}