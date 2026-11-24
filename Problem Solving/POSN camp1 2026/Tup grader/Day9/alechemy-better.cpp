#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> factor;
    vector<long long> count;
    long long m = n;
    int j = 0;
    
    for (long long i = 2; i * i <= m; i++) {
        if (n % i == 0) {
            factor.push_back(i);
            count.push_back(0);
            while (n % i == 0) {
                n /= i;
                count[j]++;
            }
            j++;
        }
    }

    if (n > 1) {
        factor.push_back(n);
        count.push_back(1);
    }


    for (int i = 0; i < factor.size(); i++) {
        cout << factor[i] << "^" << count[i];
        if (i == factor.size() - 1) break;
        cout << " " << "x" << " ";
    }

    return 0;
}