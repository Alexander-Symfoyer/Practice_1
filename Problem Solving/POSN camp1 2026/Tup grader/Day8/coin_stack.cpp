#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int q;
    cin >> q;

    vector<int> coins;
    vector<int> mins;
    for (int i = 0; i < q; i++) {
        int code;
        cin >> code;
        if (code == 1) {
            int coin;
            cin >> coin;
            coins.push_back(coin);

            if (mins.empty()) {
                mins.push_back(coin);
            }
            else {
                mins.push_back(min(coin, mins.back()));
            }
        }
        else if (code == 2) {
            coins.pop_back();
            mins.pop_back();
        }
        else if (code == 3) {
            cout << mins.back() << '\n';
        }
    }

    return 0;
}