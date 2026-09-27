#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    int m = 3;      
    int n = 3;      

    int i = m - 1;      //* Last element in nums1
    int j = n - 1;      //* Last element in nums2
    int k = m + n - 1;      //* Position where we write the next largest element

    while (j >= 0) {        //* Continue until all elements from nums2 are merged

        if (i >= 0 && nums1[i] > nums2[j]) {    //* Put the larger element at the back
            nums1[k] = nums1[i];
            i--;
        }

        else {
            nums1[k] = nums2[j];
            j--;
        }

        k--;        //* Move to the previous position

    }

}