#include <iostream>
#include <vector>
using namespace std;
int main() {                        //* Boyer-moore voting algorithm

    vector<int> nums = {3,2,3};
    int count = 0;
    int candidate = 0;
    for (int i = 0; i < nums.size(); i++) {

        if (count == 0) candidate = nums[i];
        if (nums[i] == candidate) {
            count++;
        }
        else {
            count--;
        }

    }
    cout << candidate;

}