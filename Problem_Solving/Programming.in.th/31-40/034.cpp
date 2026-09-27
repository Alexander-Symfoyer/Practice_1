#include <iostream>             //? Ax^2 + Bx + C = 0
using namespace std;            //? (ax + b)(cx + d)
int main() {                    //? A = ac, B = ad + bc, C = bd

    int A, B, C;
    cin >> A >> B >> C;

    for (int a = 1; a <= A; a++) {

        if (A % a != 0) continue;
        int c = A / a;

        for (int b = -100; b <= 100; b++){
            for (int d = -100; d <= 100; d++){

                if (b * d != C) continue;
                if (a * d + b * c != B) continue;

                cout << a << " " << b << " " << c << " " << d;
                return 0;
    
            }
        }

    }

    cout << "No Solution";
    return 0;

}