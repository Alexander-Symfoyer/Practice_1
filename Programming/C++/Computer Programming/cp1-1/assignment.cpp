#include <iostream>

using namespace std;

int main() {
    double a1, a2, a3;
    cout << "Enter the first value "  ;   cin >> a1;
    cout << "Enter the second value " ;   cin >> a2;
    cout << "Enter the third value "  ;   cin >> a3;
    double sum = a1+a2+a3;
    double average = sum/3;
    cout << "Average is " << (a1+a2+a3) / 3 << endl;

}
