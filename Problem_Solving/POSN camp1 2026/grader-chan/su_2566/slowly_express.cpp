#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int last_weight = 0;

    while (true) {

        int weight;
        cin >> weight;
        if (weight < 0) break;

        int total_weight = weight + last_weight;
        int amount = total_weight / 800;
        int remaining = total_weight % 800;

        if (remaining >= 500) {
            amount++;
            remaining -= 500;
        }

        last_weight = remaining;
        cout << amount << '\n';

    }

}