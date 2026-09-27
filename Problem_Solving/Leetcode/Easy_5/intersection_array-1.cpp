#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> ans;
    ans.reserve(min(nums1.size(), nums2.size()));

    unordered_set<int> seen;
    for (const int& x : nums1) {
        seen.insert(x);
    }

    for (const int& x : nums2) {
        if (seen.find(x) != seen.end()) {
            ans.push_back(x);
            seen.erase(x);
        }
    }

    for (const int& y : ans) {
        printf("%d", y);
        printf(" ");
    }   printf("\n");

}