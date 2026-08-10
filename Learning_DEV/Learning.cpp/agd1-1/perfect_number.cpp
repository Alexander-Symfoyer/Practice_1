#include <iostream>


using namespace std;


int find(int &a, int &b) {

    for (int i = a; i < b; i++) {

        int k = 0;
        for (int j = 1; j < i; j++) {

        
            if (i % j == 0) {

                k += j;

            }

        }
        
        if (k == i) cout << k << " ";

    }
    cout << '\n';

}


int main() {

    int a,b;
    cout << "Enter a : ";   cin >> a;
    cout << "Enter b : ";   cin >> b;
    find(a,b);

}