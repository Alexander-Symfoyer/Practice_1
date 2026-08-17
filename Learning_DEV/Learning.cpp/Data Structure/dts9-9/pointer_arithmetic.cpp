#include <iostream>

using namespace std;

int main() {

    bool x, y, z;
    x = 1, y = 2, z = 3;
    bool *a, *b;

    a = &x;
    b = a + 2;

    cout << &x << '\n';
    cout << &y << '\n';
    cout << &z << '\n';

    cout << a << '\n';
    cout << b << '\n';

    cout << b - a << '\n';

}