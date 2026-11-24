#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<double> nums(20);
    double sum = 0;
    for (int i = 0; i < 20; i++) {
        cin >> nums[i];
        sum += nums[i];
    }

    double avg = sum / 20;
    double nearest = nums[0];
    for (int i = 0; i < 20; i++) {
        if (abs(nums[i] - avg) < abs(nearest - avg)) {
            nearest = nums[i];
        }
    }

    cout << fixed << setprecision(1) << nearest;

    return 0;
}