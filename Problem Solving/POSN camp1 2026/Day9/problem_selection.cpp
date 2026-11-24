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

    for (int i = 0; i < n; i++) {
        stack<int> st;
        long long fun = 0;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            while (!st.empty() && st.top() <= easy[j]) {
                st.pop();
            }
            if ((!st.empty() && st.top() > easy[j]) || st.empty()) {
                st.push(easy[j]);
            }
        }
        while (!st.empty()) {
            fun += st.top();
            st.pop();
        }
        cout << fun << " ";
    }

    cout << '\n';

}