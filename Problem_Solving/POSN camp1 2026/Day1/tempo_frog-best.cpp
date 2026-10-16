#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int current;
    cin >> current;

    int count = 1;

    stack<int> st;

    for (int i = 1; i < n; i++) {
        int x;
        cin >> x;

        if (x == current) {
            count++;
        }
        else {
            // Process the previous group
            if (count == 1) {
                if (!st.empty() && st.top() == current) {
                    st.pop();
                }
                else {
                    st.push(current);
                }
            }

            current = x;
            count = 1;
        }
    }

    // Process the last group
    if (count == 1) {
        if (!st.empty() && st.top() == current) {
            st.pop();
        }
        else {
            st.push(current);
        }
    }

    if (st.empty()) {
        cout << "empty\n";
        return 0;
    }

    vector<int> answer;

    while (!st.empty()) {
        answer.push_back(st.top());
        st.pop();
    }

    reverse(answer.begin(), answer.end());

    cout << answer.size() << '\n';

    for (int x : answer) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}