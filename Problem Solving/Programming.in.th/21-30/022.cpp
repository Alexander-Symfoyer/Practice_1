#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main() {

    int n; cin >> n;
    int width = (n % 2 == 1 ? n : n - 1);     //* Ternary operator
    int center = width / 2;

    for (int i = 0; i < n; i++) {

        int d;
        if (i <= center) d = i;
        else d = n - 1 - i;
        
        int left = center - d;
        int right = center + d;

        for (int j = 0; j < width; j++) {
            if (j == left || j == right) {
                cout << "*";
            }   else {
                cout << "-";
            }
        }
        cout << '\n';

    }

}