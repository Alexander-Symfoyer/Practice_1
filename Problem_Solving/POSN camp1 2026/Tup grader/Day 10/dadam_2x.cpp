#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long n, area;
    cin >> n >> area;
    vector<long long> areas(area + 1, 1);
    for (int i = 0; i < n; i++) {
        long long pole,index;
        cin >> index >> pole;
        areas[index] = pole + 1;
    }

    stack<int> st;
    long long rains = 0;
    
    for (int i = 0; i < area; i++) {
        while (!st.empty() && areas[st.top()] <= areas[i]) {
            int mid = st.top();
            st.pop();
            if (st.empty()) break;
            int left = st.top();
            int right = i;

            int width = i - left - 1;
            int height = min(areas[left], areas[right]) - areas[mid];
            rains += (width * height);
        }
        st.push(i);
    }

    cout << rains << '\n';

    return 0;
}