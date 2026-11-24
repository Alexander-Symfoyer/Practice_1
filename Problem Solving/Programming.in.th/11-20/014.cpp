#include <iostream>
using namespace std;

int gcd(int a, int b) {

    while(b != 0) {
        swap(a,b);
        b %= a;
    }

    return a;

}

int main() {

    int a,b;
    cin >> a >> b;

    cout << gcd(a, b);

}