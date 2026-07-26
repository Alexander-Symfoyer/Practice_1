#include <iostream>
using namespace std;

int main() {
    int sum = 0;
    int n;
    cout << "Enter N : "; cin >> n;
    for (int i = 1; i <= n; i += 2) {
        sum += i;
    }
    cout << "Sum of odd number is " << sum << endl;
}