#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, q;
    cin >> n >> k >> q;

    if (n <= 1 || n > 2000 || k <= 1 || k >= 5000) return 0;

    vector<int> status(n);
    for (int i = 0; i < n; i++) {
        cin >> status[i];
        if (status[i] < 1 || status[i] > 300) return 0;
    }

   
    for (int i = 0; i < q; i++) {
        string fruit, code;
        int weight;
        cin >> fruit >> weight >> code;

        long long price = 1;
        if (fruit == "Carrot") {
            price *= 75;
        }
        else if (fruit == "Bamboo") {
            price *= 100;
        }
        else if (fruit == "Apple") {
            price *= 125;
        }

        price *= weight;
        
        vector<int> multipiers;
        for (int i = 0; i < n; i++) {
            if (code[i] == '1') {
                multipiers.push_back(status[i]);
            }
        }

        sort(multipiers.rbegin(), multipiers.rend());
        int take = min(k, (int)multipiers.size());
        for (int i = 0; i < take; i++) {
            price *= multipiers[i];
        }

        cout << price << '\n';

    }

    return 0;
}