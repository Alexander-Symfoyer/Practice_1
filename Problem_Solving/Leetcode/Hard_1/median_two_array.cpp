#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {1,2,3,5};
    vector<int> nums2 = {4,6,7,9,10};

    if (nums1.size() > nums2.size()) {
        swap(nums1, nums2);
    }

    int m = nums1.size();
    int n = nums2.size();
    int left = 0;
    int right = m;

    while (left <= right) {
        int partition_a = left + (right - left) / 2;
        int partition_b = (m + n + 1) / 2 - partition_a;

        int left_a = (partition_a == 0) ? INT_MIN : nums1[partition_a - 1];
        int right_a = (partition_a == m) ? INT_MAX : nums1[partition_a];
        int left_b = (partition_b == 0) ? INT_MIN : nums2[partition_b - 1];
        int right_b = (partition_b == n) ? INT_MAX : nums2[partition_b];

        if (left_a <= right_b && left_b <= right_a) {
            if ((m + n) % 2 == 0) {
                cout << (max(left_a, left_b) + min(right_a, right_b)) / 2.0;
                return 0;
            }
            else {
                cout << max(left_a, left_b);
                return 0;
            }
        }

        if (left_a > right_b){
            right = partition_a - 1;
        }
        else if (left_b > left_a) {
            left = partition_a + 1;
        }

    }

    return 0.0;

}