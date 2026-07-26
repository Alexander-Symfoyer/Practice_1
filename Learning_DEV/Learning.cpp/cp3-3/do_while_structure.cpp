#include <iostream>
using namespace std;

int main() {
    int n;
    do {
        cout << "Enter N : "; cin >> n;
        int row = 0;
        while (row++ < n) {       //row = 0
            int col = n - row;    //row = 1
            while (col--) cout << " "; //col = 0(false) = stop
            col = row * 2 - 1;
            while (col--) cout << "*";
            cout << endl;
        }
    } while (n != -1);
}