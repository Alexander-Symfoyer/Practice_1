#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a1;
    cout << M_PI << endl;
    a1 = cos(M_PI);
    cout << a1 << endl;

    cout << " "  << endl;

    cout << sin(3.1) << endl;
    cout << sin(3.14) << endl;
    cout << sin(3.141) << endl;
    cout << sin(3.1415) << endl;
    cout << sin(M_PI) << endl;

    cout << " "  << endl;

    cout << abs(-1) << endl;
    cout << sqrt(4) << endl;
    cout << log10(1000) << endl;
    cout << pow(5,2) << endl;
    cout << max(10,12) << " " << min(11,9) << endl;
    cout << floor(3.999) << " " << ceil(3.001) << endl;

    cout << " "  << endl;

    // compound assignment 
    int a2 = 10;
    a2 *= 10;
    cout << a2 << endl;
    a2 /= 10;
    cout << a2 << endl;

    cout << " "  << endl;

    cout << 3/5 << endl;
    cout << 3.0/5 << endl;
    cout << 3/5.0 << endl;

    int z = 3;
    z = z += z++ * 5 + abs(-3*4);
    cout << z << endl;
    z = 3;
    z = z += ++z * 5 + abs(-3*4);
    cout << z << endl;

} 