#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    scanf("%d", &num);
    string ans = "";

    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"},
        {400, "CD"}, {100, "C"}, {90, "XC"}, 
        {50, "L"}, {40, "XL"}, {10, "X"}, 
        {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };

    for (auto [value, symbol] : roman) {            // * Stuctured binding
        while (num >= value) {
            ans += symbol;
            num -= value;
        }
    }

    cout << ans << '\n';

}