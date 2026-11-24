#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (i == 0 || nums[i] != nums[i-1]) {
            count++;
        }
    }

    cout << count << '\n';

}