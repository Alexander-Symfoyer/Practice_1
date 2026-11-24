#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums(n);
    unordered_map<int, int> freq = {};
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        freq[nums[i]]++;
    }

    unordered_set<int> odd;
    for (int i = 0; i < nums[i]; i++) {
        if (freq[nums[i]] % 2 == 0) {
            odd.insert(nums[i]);
        }
    }

    int min_value = INT_MAX;
    for (const int& i : odd) {
        min_value = min(min_value, i);
    }

    cout << min_value;

}