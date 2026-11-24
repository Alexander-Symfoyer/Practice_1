#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter a number : "; cin >> n;
    bool prime = true;
    for (int div = 2; div * div <= n; div++) {
        if (n % div == 0) {
            prime = false;
            break;
        }
    }
    if (prime) {
        cout << n << " is a prime." << endl;
    } else {
        cout << n << " isn't prime." << endl;
    }
}