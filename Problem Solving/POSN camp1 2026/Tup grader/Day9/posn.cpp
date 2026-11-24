#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> scrap(n);
    vector<int> part(n);

    int multi = 1;

    for (int i = 0; i < n; i++) {
        cin >> scrap[i] >> part[i];
        multi *= part[i];
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        scrap[i] *= (multi / part[i]);
        sum += scrap[i];
    }

    cout << sum / multi << " ";
    int sc = sum % multi;
    int pt = multi;

    for (int i = 2; i < max(sc, pt); i++) {
        while (pt % i == 0 && sc % i == 0) {
            pt /= i;
            sc /= i;
        }
    }

    cout << sc << " ";
    cout << pt << '\n';

    return 0;
}