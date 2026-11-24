#include <iostream>
using namespace std;
int main() {

    int n = 128;
    int count = 0;
    while (n != 0) {
        if (n & 1) {
            count++;
        }
        n >>= 1;
    }

    cout << count;

}