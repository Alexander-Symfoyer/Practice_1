#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double a = 30.99;
    int b = 30.99;
    cout << a << " , " << b << endl;

    a = 12345678900;
    b = 12345678900;
    cout << a << " , " << b << endl;
    
    a = 12345678900987654321;
    cout << setprecision(15) << a << endl;
}

// 1.234567e + 10 = 1.234567 * (10 ** 10)
// 9.42e -2 = 9.42 * (10 ** -2)  =  0.0942

// int E [-2,147,483,648 , 2,147,483,647]
// b = -539222988  because of "overflow"