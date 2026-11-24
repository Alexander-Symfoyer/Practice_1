#include <iostream>
#include <vector>
using namespace std;        //* Binary search = O(log n)
int main() {

    vector<int> nums = {1,3,5,6};
    int target = 7;

    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {

        int mid = (right + left) / 2;

        if (nums[mid] == target) {
            cout << mid;
        }
        else if (nums[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }

    }

    cout << left;

}