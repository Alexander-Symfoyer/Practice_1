#include <bits/stdc++.h>
using namespace std;

const int MAXS = 26000;              
typedef bitset<MAXS + 1> BS;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> v(n);
    for (int &x : v) scanf("%d", &x);

    vector<BS> pre(n + 1), suf(n + 1);
    pre[0][0] = 1;
    for (int i = 0; i < n; i++)
        pre[i + 1] = pre[i] | (pre[i] << v[i]);

    suf[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] | (suf[i + 1] << v[i]);

    int bestDiff = INT_MAX, bestA = 0;

    for (int p = 0; p <= n; p++) {
        vector<int> B;                       
        for (int b = 0; b <= MAXS; b++)
            if (suf[p][b]) B.push_back(b);

        for (int a = 0; a <= MAXS; a++) {
            if (!pre[p][a]) continue;

            int lo = (a == 0) ? 1 : 0;       
            auto it = lower_bound(B.begin(), B.end(), max(a, lo));

            vector<int> cand;                
            if (it != B.end()) cand.push_back(*it);
            if (it != B.begin()) {
                int b = *prev(it);
                if (a > 0 || b > 0) cand.push_back(b);
            }
            for (int b : cand) {
                int diff = abs(a - b);
                if (diff < bestDiff || (diff == bestDiff && a > bestA)) {
                    bestDiff = diff;
                    bestA = a;
                }
            }
        }
    }

    printf("%d %d\n", bestA, bestDiff);
    return 0;
}