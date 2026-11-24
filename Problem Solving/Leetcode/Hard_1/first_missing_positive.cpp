#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {3, 4, -1, 1, 1};
    int n = nums.size();

    for (int i = 0; i < n; i++) {
        while (nums[i] >= 1 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] != i + 1) {
            cout << i + 1;
            return 0;
        }
    }

    cout << n + 1;

}