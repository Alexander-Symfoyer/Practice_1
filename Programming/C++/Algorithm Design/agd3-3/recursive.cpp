#include <iostream>

using namespace std;


int recursive(int n) {

    if (n <= 0) {               //* Terminating case
        return 0;
    }
    else {
        return recursive(n - 1) + n;    //* Recursion case
    }

}


void draw_tri(int level, int max) {

    if (level <= max) {                     //* Termination case

        for (int j = 0; j < level; j++) {
            cout << "*";                    //* Most executed line --> O(level)
        }
        cout << '\n';
        draw_tri(level + 1, max);           //* Recursion case

    }

}


int gcd(int a, int b) {                 //! Worst case b reduce by half every time

    if (b == 0) return a;               //* log(b)
    return gcd(b, a % b);

}


int main() {

    int n = 10;
    cout << recursive(n) << '\n';

    int level = 1;
    int max = 5;
    draw_tri(level, max);

    int a = 900;
    int b = 400;
    cout << gcd(a, b) << '\n';
}