#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {

        int n, k;
        cin >> n >> k;
        vector<int> count(3,0);
        string s;
        cin >> s;

        for (const char& c : s) {
            if (c == 0) count[0]++;
            else if (c == 1) count[1]++;
            else count[2]++;
        }

        

    }

    return 0;
}