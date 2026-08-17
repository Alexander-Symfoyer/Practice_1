#include <iostream>
using namespace std;

void print(char c[], int n) {
    for (int i = 0; i < n; i++)
        cout << c[i];
    cout << endl;
}

void fill(char a[], char value, int begin, int end) {
    while (begin < end)
        a[begin++] = value;
}

void test(int a) {
    a = 10;
}

int main() {
    int a = 5;
    test(a);
    cout << "a is " << a << endl;

    char c[10];
    for (int i = 0; i < 10; i++) c[i] = 'a';
    print(c, 10);
    fill(c, 'x', 3, 6);
    print(c, 10);
}
