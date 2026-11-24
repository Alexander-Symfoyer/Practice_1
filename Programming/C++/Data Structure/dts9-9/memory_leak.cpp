#include <iostream>

using namespace std;

void leaked() {
    int *a;
    a = new int[200];
}

int main () {
    for (int i = 0; i < 100000; i++) {
        int *a;
        cout << i << '\n';
        leaked();
    }
}
//! smarter pointer can help