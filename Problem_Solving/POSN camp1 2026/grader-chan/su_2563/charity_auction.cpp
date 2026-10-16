#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> price;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        price.push_back(x);
    }

    stack<int> latest;
    latest.push(-1);
    int sum = 0;

    for (const int& x : price) {
        if (x > latest.top()) {
            sum += x;
            latest.pop();
            latest.push(x);
        }
        else continue;
    }

    cout << sum;

}