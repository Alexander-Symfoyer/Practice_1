#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<int> target(4);
    for (int i = 0; i < 4; i++) {
        cin >> target[i];
    }
    int n;
    cin >> n;
    if (n >= 100) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> soln;

    for (int i = 0; i < n; i++) {
        int count = 0;
        int j = 0;
        while (j < 4 && (j + i) < n) {
            if (target[j] == nums[j + i]) {
                j++;
                count++;
            }
            else break;
        }
        if (count == 4) soln.push_back(i);
    }

    cout << soln.size() << '\n';
    for (const int& i : soln) {
        cout << i << " ";
    }

    return 0;
}