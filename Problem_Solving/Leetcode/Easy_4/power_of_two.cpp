#include <iostream>
using namespace std;
int main() {                //* & Bitwise and
                            // 0 & 0 = 0                        
                            // 0 & 1 = 0
                            // 1 & 0 = 0
                            // 1 & 1 = 1

    int n = 1024;
    if (n <= 0) {
        cout << "False";
        return 0;
    }

    if ((n & (n - 1)) == 0) {       //? n = 8, n - 1 = 7
        cout << "True";             //? 1000 & 0111 = 0000
        return 0;
    } 
    cout << "False";

}