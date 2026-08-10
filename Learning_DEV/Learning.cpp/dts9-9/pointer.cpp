#include <iostream>

using namespace std;

int main() {

    int x,y;
    int *a;
    int *b;

    x = 10;
    a = &x;
    b = a;
    *b = 20;
    y = *b;

    cout << &x << '\n';
    cout << x << '\n';
    cout << y << '\n';
    cout << &y << '\n';
    cout << &a << '\n';
    cout << &b << '\n';

    cout << sizeof(int) << '\n';
    cout << sizeof(int*) << '\n';

}