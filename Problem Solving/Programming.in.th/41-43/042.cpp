#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {

    int q;
    cin >> q;
    long double num;
    while (q--) {

        cin >> num;

        cout << fixed << setprecision(0)
            << pow(2.0L, num) << '\n';

    }

}