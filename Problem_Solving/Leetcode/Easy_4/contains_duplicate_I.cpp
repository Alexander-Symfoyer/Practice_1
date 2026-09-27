#include <iostream>
#include <vector>
#include <set>
using namespace std;                    //* O(n log n)
int main() {

    vector<int> nums = {2, 3, 1};
    set<int> seen;

    for (int num : nums) {
        if (seen.find(num) != seen.end()) {
            cout << "True";
            return 0;
        }
        seen.insert(num);
    }
    cout << "False";

}