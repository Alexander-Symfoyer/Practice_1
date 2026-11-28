#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    int n1 = nums1.size();
    int n2 = nums2.size();
    vector<int> ans;
    ans.reserve(min(n1, n2));

    int i = 0;
    int j = 0;
    
    while (i < n1 && j < n2) {

        if (nums1[i] < nums2[j]) {
            i++;
        }
        
        else if (nums1[i] > nums2[j]) {
            j++;
        }

        else {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }

    }

    for (const int& y : ans) {
        printf("%d", y);
        printf(" ");
    }   printf("\n");

}