#include <iostream>
using namespace std;

const int n = 10;

int main() {
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = 1;

    int b[10];
    for (int i = 0; i < sizeof(b) / sizeof(int); i++)
        b[i] = 2;

    cout << "Size of a " << sizeof(a) << endl;
    cout << "Size of b " << sizeof(b) << endl;
    cout << "Size of a[i] " << sizeof(a[1]) << endl;
}

//size of == bytes
//int = 4, double = 8, bool = 1