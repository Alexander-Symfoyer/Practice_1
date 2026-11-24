#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> nums1(10), nums2(10);
    unordered_map<int, bool> count2 = {};
    for (int i = 0; i < 10; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < 10; i++) {
        cin >> nums2[i];
        count2[nums2[i]] = true;
    }

    for (int i = 0; i < 10; i++) {
        if (count2[nums1[i]] == true) {
            cout << nums1[i] << '\n';
        }
    }

}