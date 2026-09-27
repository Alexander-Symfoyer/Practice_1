#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main() {

    vector<int> nums = {1,2,3,1};
    int k = 3;

    unordered_map<int, int> lastindex;
    for (int i = 0; i < nums.size(); i++) {

        if (
            lastindex.find(nums[i]) != lastindex.end()
            && abs(i - lastindex[nums[i]]) <= k
    ) {
        cout << "True";
        return 0;
        }

        lastindex[nums[i]] = i;

    }

    cout << "False";

}