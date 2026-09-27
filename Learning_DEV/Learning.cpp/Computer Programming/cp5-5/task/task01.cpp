#include <bits/stdc++.h>
using namespace std;

int two_sum(const vector<int>& v, int target) {     //! O(n)

    if (v.empty()) return 0;    //* Edge cases;

    int n = v.size();
    int count = 0;
    unordered_map<int, int> freq;

    for (const int& num : v) {

        int goal = target - num;
        if (freq.find(goal) != freq.end()) {
            count += freq[goal];
        }
        freq[num]++;

    }

    return count;

}

int main() {

    vector<int> v = {0,1,3,2,3,4,1,5,6};
    int target = 6;

    cout << two_sum(v, target);

}