#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> pole(n, 1);
    for (int i = 0; i < k; i++) {
        int city, noise;
        cin >> city >> noise;
        
        int desi = noise;
        int j = 0;
        while (desi > 0) {
            if (desi == noise) {
                pole[city] += noise;
            }
            else {
                if (city - j >= 0) {
                    pole[city - j] += desi;
                }
                if (city + j < n) {
                    pole[city + j] += desi;
                }
            }
            j++;
            desi--;
        }

    }

    int max_pole = INT_MIN;
    for (int i = 0; i < n; i++) {
        max_pole = max(max_pole, pole[i]);
    }

    for (int i = 0; i < n; i++) {
        if (max_pole == pole[i]) {
            cout << i << " ";
        }
    }

    return 0;
}