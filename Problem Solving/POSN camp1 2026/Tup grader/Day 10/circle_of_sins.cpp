#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int m,n;
    cin >> n >> m;
    vector<int> sins(n);
    for (int i = 0; i < n; i++) {
        cin >> sins[i];
    }


    vector<bool> use(n, false);
    int count = 0;
    int j = 0;
    while (count < n) {
        int maxx = 0;
        int index = -1;

        int i = j;
        int check = 0;
        int need = min(m, n - count);

        while (check < need) {
            if (!use[i]) {
                if (sins[i] > maxx) {
                    maxx = sins[i];
                    index = i;
                }
                check++;
            }
            i = (i + 1) % n;
        }

        j = i;

        use[index] = true;
        count++;

        cout << index + 1 << " ";

        if (count == n) break;

        while (use[j]) {
            j = (j + 1) % n;
        }

    }

    cout << '\n';

    return 0;
}