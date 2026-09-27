#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};
    vector<int> soln;

    unordered_map<int, int> mp;
    stack<int> st;

    for (const int &x : nums2) {

        while (!st.empty() && x > st.top()) {
            mp[st.top()] = x;
            st.pop();
        }

        st.push(x);

    }

    for (const int &x : nums1) {
        if (mp.find(x) == mp.end()) {
            soln.push_back(-1);
        }
        else {
            soln.push_back(mp[x]);
        }
    }

    for (const int &x : soln) {
        cout << x << " ";
    }   cout << '\n';

}