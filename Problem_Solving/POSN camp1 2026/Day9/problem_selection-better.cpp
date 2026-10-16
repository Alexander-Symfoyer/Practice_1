#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> easy(n);
    for (int i = 0; i < n; i++) {
        cin >> easy[i];
    }

    vector<int> next(n, -1);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && easy[st.top()] <= easy[i]) {
            st.pop();
        }
        if (!st.empty()) {
            next[i] = st.top();
        }
        st.push(i);
    }

    cout << '\n';

}