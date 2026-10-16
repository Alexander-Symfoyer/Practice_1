#include <bits/stdc++.h>
using namespace std;

int max_value(vector<int>& nums) {

    int max_nums = INT_MIN;
    for (int i = 0; i < nums.size(); i++) {
        max_nums = max(nums[i], max_nums);
    }

    return max_nums;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums(6);
    for (int i = 0; i < nums.size(); i++) {
        cin >> nums[i];
    }

    cout << max_value(nums);

    return 0;
}