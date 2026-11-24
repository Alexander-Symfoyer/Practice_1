#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, l;
    cin >> n >> l;

    if (n < 1 || n > 100000 || l < 1 || l > min(n,100)) return 0;

    vector<int> height(n);
    vector<int> target(l);
    for (int i = 0; i < n; i++) {
        cin >> height[i];
        if (height[i] < 1 || height[i] > 1000000) return 0;
    }
    for (int i = 0; i < l; i++) {
        cin >> target[i];
        if (target[i] < 1 || target[i] > n) return 0;
    }

    int pre = height[0];
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (j < l && i + 1 == target[j]) {
            if (i == 0 || height[i] > pre) {
                cout << 0 << '\n';
            }
            else {
                cout << (pre - height[i] + 1) << '\n';
            }
            j++;
        }
        pre = max(height[i], pre);
    }

    return 0;
}