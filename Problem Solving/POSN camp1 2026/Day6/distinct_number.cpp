#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<int> distinct;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        distinct.insert(x);
    }

    cout << distinct.size() << '\n';

}