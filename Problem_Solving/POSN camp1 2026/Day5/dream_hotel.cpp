#include <bits/stdc++.h>
using namespace std;

vector<int> value;
vector<bool> ready;

int solve(int x) {

    if (x <= 0) return 0;
    if (ready[x]) return value[x];
    int best = 1e9;
    best = min(best, solve(x - 1) + 500);
    best = min(best, solve(x - 2) + 800);
    best = min(best, solve(x - 5) + 1500);
    best = min(best, solve(x - 15) + 3000);

    value[x] = best;
    ready[x] = true;

    return best;

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    value.resize(n + 1);
    ready.resize(n + 1, false);

    cout << solve(n) << '\n';

}