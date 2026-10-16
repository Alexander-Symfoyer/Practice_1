#include <bits/stdc++.h>
using namespace std;

void sort_number(vector<int>& nums, int size) {

    sort(nums.begin(), nums.end());

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];
    sort_number(nums , 3);
    cout << nums[0] << nums[1] << nums[2];

    return 0;
}