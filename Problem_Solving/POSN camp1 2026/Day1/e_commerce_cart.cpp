#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    double total_price = 0;
    while(getline(cin, line)) {

        if (line == "END") break;

        string name;
        double price, quantity;
        stringstream ss(line);
        ss >> name >> price >> quantity;

        total_price += (price * quantity);

    }

    string s;
    cin >> s;
    if (s == "SAVE10") {
        total_price *= 0.9;
    }

    cout << "TOTAL ";
    cout << fixed << setprecision(2) << total_price << '\n';

    return 0;
}