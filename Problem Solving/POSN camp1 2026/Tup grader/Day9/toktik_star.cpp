#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long one = 0;
    long long two = 0;
    long long three = 0;

    long long sum = 0;

    for (int i = 0; i < n; i++) {
        int x,y,z;
        cin >> x >> y >> z;
        one += x;
        two += y;
        three += z;
        sum += (x * 10);
        sum += (y * 20);
        sum += (z * 30);
    }

    for (int i = 0; i < one; i++) {
        cout << "#";
    }   cout << '\n';
    for (int i = 0; i < two; i++) {
        cout << "#";
    }   cout << '\n';
    for (int i = 0; i < three; i++) {
        cout << "#";
    }   cout << '\n';
    cout << sum << '\n';

    return 0;
}