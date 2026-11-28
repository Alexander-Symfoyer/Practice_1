#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1,1,0,1,1,1};
    int soln = 0;
    int n = nums.size();
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == 1) {
            count++;
        }
        else {
            soln = max(count, soln);
            count = 0;
        }
    }

    soln = max(count, soln);

    cout << soln;

}