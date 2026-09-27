#include <iostream>
using namespace std;        //! Modular arithmetic
int main() {

    int rem3 = 0;
    int rem11 = 0;
    string n; cin >> n;

    for (char c : n) {

        int digit = c - '0';

        rem3 = (rem3 * 10 + digit) % 3;
        rem11 = (rem11 * 10 + digit) % 11;

    }

    cout << rem3 << " " << rem11;

}