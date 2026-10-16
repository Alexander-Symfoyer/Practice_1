#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, s;
    cin >> n >> s;
    int max_s = s;
    int min_s = s;

    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;

        if (height % 3 == 0 && height % 4 != 0) {
            height /= 3;
            height *= 10;
            max_s -= height;
            min_s -= height;
        }
        else if (height % 3 != 0 && height % 4 == 0) {
            height /= 4;
            height *= 10;
            max_s -= height;
            min_s -= height;
        }
        else if (height % 3 == 0 && height % 4 == 0) {
            int h1 = height / 3;
            int h2 = height / 4;
            h1 *= 10;
            h2 *= 10;
            max_s -= h2;
            min_s -= h1;
        }
    }

    cout << min_s << " " << max_s << '\n';

    return 0;
}