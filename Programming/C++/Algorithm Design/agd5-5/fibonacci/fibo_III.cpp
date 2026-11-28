#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* O(n);
//* Bottom-up

int fibo_memo(int n, vector<int>& value) {
    value[0] = 0;
    value[1] = 1;
    for (int i = 2; i <= n; ++i) {
        value[i] = value[i-1] + value[i-2];
    }
    return value[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> value(n+1, 0);
    cout << fibo_memo(n, value);

}