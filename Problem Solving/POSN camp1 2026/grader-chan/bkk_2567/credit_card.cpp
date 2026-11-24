#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string digits;
    cin >> digits;

    vector<int> storage;
    int last = digits.back() - '0';
    digits.pop_back();
    reverse(digits.begin(), digits.end());

    for (int i = 0; i < digits.size() ; i++) {
        if (i % 2 == 0) {
            storage.push_back((digits[i] - '0') * 2);
        }
        else {
            storage.push_back(digits[i] - '0');
        }
    }

    int sum = 0;

    for (int i = 0; i < storage.size(); i++) {
        if (storage[i] >= 10) {
            sum += storage[i] % 10;
            sum += storage[i] / 10;
        }
        else {
            sum += storage[i];
        }
    }

    int soln = (10 - (sum % 10)) % 10;
    if (soln == last) {
        cout << "yes";
    }
    else {
        cout << "no";
    }

}