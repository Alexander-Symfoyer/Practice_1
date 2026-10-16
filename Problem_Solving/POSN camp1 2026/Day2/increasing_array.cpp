#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    long long min_move = 0;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] > nums[i+1]) {
            long long move = nums[i] - nums[i+1];
            min_move += move;
            nums[i+1] += move;
        }
    }

    cout << min_move << '\n';

    return 0;
}