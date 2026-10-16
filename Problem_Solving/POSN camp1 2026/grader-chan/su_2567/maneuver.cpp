#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> unit(n);
    for (int i = 0; i < n; i++) {
        cin >> unit[i];
    }

    vector<int> soln_1;
    vector<int> soln_2;

    int total_abs = 0;
    for (const int& x : unit) {
        total_abs += abs(x);
    }

    

}