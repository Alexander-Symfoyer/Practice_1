#include <bits/stdc++.h>
using namespace std;

int all_attacks = 0;

void choose(const int& k, vector<int>& cards, vector<int> current, vector<bool>& used, const int& n) {

    if (current.size() == k) {
        int max_cards = INT_MIN;
        for (int i = 0; i < k; i++) {
            max_cards = max(max_cards, current[i]);
        }
        all_attacks += max_cards;
        return;
    }

    for (int i = 0; i < k; i++) {
        if (used[i]) continue;
        
        current.push_back(cards[i]);
        used[i] = true;

        choose(k, cards, current, used, n);

        used[i] = false;
        current.pop_back();
    }

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
    vector<bool> used(n, false);

    choose(k, cards, {}, used, n);

    cout << all_attacks % 1000000007 << '\n';

}