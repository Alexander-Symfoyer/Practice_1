#include <iostream>
using namespace std;

int main() {
    if (1 > 2)
        cout << "a" << endl;
        cout << "b" << endl;

    int d;
    cout << "Enter a number "; cin >> d;
    if (d % 2 == 0) {
        cout << "It is even." << endl;
    }
    else {
        cout << "It is odd." << endl;
    }

    bool x = true;
    if (x) cout << "yes"; else cout << "no";

    int a,b,c;
    cout << "Enter 3 numbers : "; 
    cin >> a >> b >> c;
    if(a > b && a >= c) cout << "Largest is " << a << endl;
    if(b >= a && b > c) cout << "Largest is " << b << endl;
    if((c > a && c >= b) || (a==b && a==c && b==c)) cout << "Largest is " << c << endl;
    
}
