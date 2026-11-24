#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {-1,0,3,4,-3};
    int target = 2;
    int closest = nums[0] + nums[1] + nums[nums.size() - 1];
    
    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++) {
        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }
        int l = i + 1;
        int r = nums.size() - 1;
        while (l < r) {
            int sum = nums[l] + nums[r] + nums[i]; 

            if (abs(closest - target) > abs(sum - target)) {
                closest = sum;
            }

            if (sum == target) {
                cout << target;
                return 0;
            }
            else if (sum > target) {
                r--;
            }
            else if (sum < target) {
                l++;
            }

        }
    }

    cout << closest;

}