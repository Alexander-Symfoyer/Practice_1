#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> g = {1,2,3};
    vector<int> s = {1,1};

    int soln = 0;
    int i = 0;
    int j = 0;

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    while (i < g.size() && j < s.size()) {
        if (g[i] <= s[j]) {
            soln++;
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    cout << soln;

}