#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    long long j, t, e;
    cin >> j >> t >> e;

    long long jj = j;
    long long tt = t;
    while (t != 0) {
        long long temp = t;
        t = j % t;
        j = temp;
    }

    long long gcd = j;
    long long crn = (jj * tt) / gcd;
    long long round = e / crn;

    if (round % 2 == 0) {
        cout << "JERRY";
    } 
    else cout << "TOM";

    return 0;
}