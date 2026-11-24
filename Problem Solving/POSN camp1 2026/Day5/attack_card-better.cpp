#include <bits/stdc++.h>
using namespace std;

int all_attacks = 0;
const long long mod = 1000000007;
long long fact[10001];

void init() {
    fact[0] = 1;
    for (int i = 0; i < 10000; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
}

void combi() {
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        cin >> cards[i];
    }
    sort(cards.begin(), cards.end());

    long long ans = 0;
    for (int i = k - 1; i < n; i++) {

    }

    cout << all_attacks % mod << '\n';

}