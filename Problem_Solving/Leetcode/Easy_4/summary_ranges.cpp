#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> nums = {0,1,2,4,5,7};
    vector<string> result;  
    
    if (nums.empty()) {
        cout << "{}";
        return 0;
    }

    int start = nums[0];        //* Start of current range

    for (int i = 1; i < nums.size(); i++) {
        
        if (nums[i] != nums[i-1] + 1) {     //* Check if not consecutive

            if (start == nums[i-1]) {               //* Start and end are the same
                result.push_back(to_string(start)); //* Only one number
            }

            else {
                result.push_back(to_string(start) + "->" + to_string(nums[i-1]));       //* Range
            }

            start = nums[i];        //* Start a new range

        }
    }

    if (start == nums.back()) {                 //* Handle the last range after the loops end
        result.push_back(to_string(start));
    }

    else {
        result.push_back((to_string(start)) + "->" + to_string(nums.back()));
    }

    for (string s : result) {
        cout << s << " ";
    } cout << '\n';

}