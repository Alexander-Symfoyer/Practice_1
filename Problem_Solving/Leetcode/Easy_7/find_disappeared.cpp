#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {4,3,2,7,8,2,3,1};
    int n = nums.size();
    vector<int> soln;
    
    for (int i = 0; i < n; i++) {
        int x = abs(nums[i]);
        int index = x -1;
        nums[index] = -abs(nums[index]);
    }

    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            soln.push_back(i + 1);
        }
    }

    for (const int& x : soln) {
        cout << x << " ";
    }

}