#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> macaron(n);
    for (int i = 0; i < n; i++) {
        cin >> macaron[i];
    }

    long long topping = 0;
    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            st.push(i);
            continue;
        }
        if (!st.empty() && macaron[i] != 0) {
            int left = st.top();
            int right = i;
            int width = right - left - 1;
            int height = min(macaron[left], macaron[right]);
            topping += (width * height);
            st.push(i);
        }
        else if (macaron[i] == 0) continue;
    }

    cout << topping << '\n';
    
    return 0;
}