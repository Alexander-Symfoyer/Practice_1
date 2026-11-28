#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//* O(n);
//* Top-down

int fibo_memo(int n, vector<int>& table) {
    if (n == 1 || n == 2) return n;
    if (n >= 2) {
        if (table[n] > 0) {
            return table[n];    //! memorization
        }
        int value = fibo_memo(n-1, table) + fibo_memo(n-2, table);
        table[n] = value;        //! memorization
        return value;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> table(n+1, 0);
    cout << fibo_memo(n, table);

}