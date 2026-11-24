#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    stack<int> st;
    for (int x : v) {
        if (!st.empty() && x == st.top()) {
            st.pop();
        }
        else {
            st.push(x);
        }
    }

    if (st.empty()) {
        cout << "empty";
    }
    else {
        vector<int> out;
        while (!st.empty()) {
            out.push_back(st.top());
            st.pop();
        }

        reverse(out.begin(), out.end());
        
        cout << out.size() << '\n';
        for (const int& i : out) {
            cout << i << " ";
        }
    }

}