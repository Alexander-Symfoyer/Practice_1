#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m, k;             //? n = applicants, m = apartments, k = difference   
    cin >> n >> m >> k;
    vector<int> app(n);
    vector<int> apart(m);

    for (int i = 0; i < n; i ++) {
        cin >> app[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> apart[i];
    }

    int get = 0;

    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());
    int i = 0;
    int j = 0;
    while (i < n && j < m) {

        if (apart[j] > app[i] + k) {
            i++;
        }
        else if (apart[j] < app[i] - k) {
            j++;
        }
        else {
            get++;
            i++;
            j++;
        }

    }

    cout << get << '\n';

    return 0;
}