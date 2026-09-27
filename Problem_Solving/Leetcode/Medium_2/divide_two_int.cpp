#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dividend = 10;
    int divisor = 3;
    long long quotient = 0;
    
    long long dvd = dividend;
    long long dvs = divisor;

    if (dvd < 0) dvd = -dvd;
    if (dvs < 0) dvs = -dvs;

    while (dvd >= dvs) {

        long long temp = dvs;
        long long multiple = 1;
        while ((temp << 1) <= dvd) {
            temp <<= 1;
            multiple <<= 1;
        }
        dvd -= temp;
        quotient += multiple;
    }

    bool negative = (dividend < 0) ^ (divisor < 0);
    if (negative) quotient = - quotient;

    if (quotient > INT_MAX) {
        cout << INT_MAX;
        return 0;
    }
    
    if (quotient < INT_MIN) {
        cout << INT_MIN;
        return 0;
    }

    cout << (int)quotient << '\n';

}