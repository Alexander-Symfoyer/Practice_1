#include <iostream>

using namespace std;

class test{
public:

    test() : data() {cout << "created" << '\n';}       
    ~test() {cout << data <<  " destroyed " << '\n';}

    int data;

};

int main() {

    cout << "   - Life cycle -   " << '\n';
    test u;
    u.data = 99;

    for (int i = 0; i < 5; i++) {
        test t;
        t.data = i*10;
    }

}
