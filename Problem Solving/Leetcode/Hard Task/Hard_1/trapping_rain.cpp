#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int rains = 0;
    stack<int> st;

    for (int i = 0; i < height.size(); i++) {

        while (!st.empty() && height[i] >= height[st.top()]) {

            int middle = st.top();
            st.pop();

            if (st.empty()) break;

            int left = st.top();
            int width = i - left - 1;
            int water_height = min(height[left], height[i]) - height[middle];

            rains += width * water_height;

        }

        st.push(i);

    }

    cout << rains;

}

//* (i−left−1)×(min(hleft​,hright​)−hmiddle​)
//! O(n)