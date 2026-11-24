#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans;
    ans.reserve(min(nums1.size(), nums2.size()));

    unordered_map<int, int> count;
    for (const int& x : nums1) {
        count[x]++;
    }

    for (const int& x : nums2) {
        if (count[x] > 0) {
            ans.push_back(x);
            count[x]--;
        }
    }
    

    for (const int& y : ans) {
        printf("%d", y);
        printf(" ");
    }   printf("\n");

}