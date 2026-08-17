#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    int a;
    cin >> a;
    if (a != 0) 
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    double x,y,z;
    x = 987654.23456789;
    y = 0.1234567;
    z = 3456789123;

    double p = x / y / z;
    double q = x / z / y;

    if (p == q) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    cout << setprecision(20);
    cout << p << endl << q << endl;

    cout << 5 % 3 << endl << -5 % 3 << endl;
    cout << 5 % -3 << endl << -5 % -3 << endl;

    double r = 30;
    double v1 = (double)4 / 3 * M_PI * r * r * r;
    double v2 = r * r * r * 4 / 3 * M_PI;  // correct!

    cout << v1 << endl << v2 << endl;

    cout << " " << endl;   // implicit conversion
    
    cout << 'a' << endl;
    cout << (int)'a' << endl;  //type cast
    cout << (char)105 << endl;
    cout << (int)3.15 << endl;

}

// Every number that not 0 is true