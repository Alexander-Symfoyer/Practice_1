#include <iostream>
using namespace std;

void test1(int a[3]) {
    cout << "test 1 size = " << sizeof(a) << endl;
    for (int i = 0; i < 5; i++) cout << a[i] << " ";
    cout << endl;
}

void test2(int a[100]) {
    cout << "test 2 size = " << sizeof(a) << endl;
    for (int i = 0; i < 5; i++) cout << a[i] << " ";
    cout << endl;
}

int main() {
    int a[3];
    int b[7];

    for (int i = 0; i < 3; i++) a[i] = i;
    for (int i = 0; i < 7; i++) b[i] = i * 10;

    test1(a);
    test2(a);
    test1(b);
    test2(b);

    return 0;
}

//pointer = 8 bytes