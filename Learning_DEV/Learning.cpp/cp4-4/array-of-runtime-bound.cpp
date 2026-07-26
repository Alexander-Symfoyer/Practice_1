#include <iostream>
using namespace std;

void test(int a[], int n) {
    cout << a[n-1] << endl;
}

int main() {
    int n;
    cout << "Enter length : "; cin >> n;
    int v[n] = {0};
    cout << "Size = " << sizeof(v) << endl;
    test(v,10);
}