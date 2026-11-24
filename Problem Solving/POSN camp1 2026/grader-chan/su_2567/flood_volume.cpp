#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> soils(n);
    for (int i = 0; i < n; i++) {
        cin >> soils[i];
    }

    int rains = 0;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++) {

        while (!st.empty() && soils[st.top()] <= soils[i]) {

            int middle = st.top();
            st.pop();
            
            if (st.empty()) break;

            int left = st.top();
            int right = i;

            int water_height = min(soils[left], soils[right]) - soils[middle];
            int distance = right - left - 1;
            rains += water_height * distance;

        }

        st.push(i);

    }

    cout << rains;

}