#include <bits/stdc++.h>
using namespace std;

int find_first (vector<int>& nums,  const int& target) {

    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans = mid;
            right = mid - 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    return ans;

}

int find_last (vector<int>& nums, const int& target) {

    int left = 0;
    int right = nums.size() - 1;
    int ans = -1;

    while (left <= right) {

        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            ans = mid;
            left = mid + 1;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    return ans;

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    cout << find_first(nums, target);
    cout << " " << find_last(nums, target) << '\n';

}