#include <iostream>
using namespace std;

int main() {
    int n,row;
    cout << "Enter N : "; cin >> n;
    row = n;
    while (row--) {
        int col = 1;
        while (col <= n) {
            cout << (col++ < n - row ? " " : "*");
        }
        cout << endl;
    }
}