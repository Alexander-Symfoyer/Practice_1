#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n < 0 || n > 50) return 0;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        if (nums[i] > 10) return 0;
    }

    int k;
    cin >> k;
    if (k > 10) return 0;

    bool found = false;
    bool first = true;
    for (int i = 0; i < n; i++) {
        if (nums[i] > k) {
            if (!first) cout << ", ";
            cout << i;
            first = false;
            found = true;
        }
    }

    if (!found) cout << "Notfound";

}