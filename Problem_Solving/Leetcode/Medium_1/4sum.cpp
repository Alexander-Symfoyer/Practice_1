#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    vector<vector<int>> ans;

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {

        if (i > 0 && nums[i] == nums[i-1]) {
            continue;
        }

        for (int j = i + 1; j < nums.size(); j++) {

            if (j > i + 1 && nums[j] == nums[j-1]) {
                continue;
            }

            int l = j + 1;
            int r = nums.size() - 1;
            while (l < r) {
                    
                long long sum = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                if (sum == target) {
                    ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l < r && nums[l] == nums[l-1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r+1]) {
                        r--;
                    }
                }
                else if (sum < target) {
                    l++;
                }
                else if (sum > target) {
                    r--;
                }

            }

            
        }

    }

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }   cout << '\n';
    }

}