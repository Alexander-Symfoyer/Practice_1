#include <iostream>
#include <stack>
using namespace std;


void test(int x) {      // Stack method
    if (x > 0) {
        int y = x - 1;
        cout <<  "I am test (" << x <<"). continue..." << endl;
        test(y);
    } 
    else {
        cout << "I am test(0). stop..." << endl;
    }
}


void b(int x) {                             //* Call function == push stack
    ++x;                                    //* End function == pop stack and return address
    cout << "X is " << x << endl;
    cout << "Address is : "<< &x << endl;       //* &x = address of x
}


void a(int x, int y) {                      //? Address = Address number of data in RAM
    int z = x / y;                          //? Use address to find the next commmand
    b(z);                                   // EX 0x4015b0 0x401656
    cout << "Z is " << z << endl;
    cout << "Address is : " << &z << endl;
}


int main() {
    a(3,2);
    b(5);
    test(4);
    return 0;
}