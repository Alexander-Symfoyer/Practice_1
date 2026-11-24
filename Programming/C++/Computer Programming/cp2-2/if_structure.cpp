#include <iostream>
using namespace std;

int main() {
    int a;
    cout << "Enter value : "; cin >> a;
    if (a >= 200){
        cout << "You recieve a discount of 10%" << endl;
        a *= 0.9;
    cout << "The price is " << a << endl;
    }
}