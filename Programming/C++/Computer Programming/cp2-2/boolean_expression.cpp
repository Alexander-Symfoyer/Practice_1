#include <iostream>
using namespace std;

//boolean 0 false  1 true

int main() {
    cout << (1 < 2) << endl;
    cout << (1 > 2) << endl;

    bool a,b,c;
    a = (1 == 2);
    b = 'a' != 'b';
    c = '1' < 'a';
    cout << a << b << c << endl;

    cout << (a || b) << endl;
    cout << (a && b) << endl;
    cout << !(a && b) << endl;

    cout << ("a" == "a") << endl;
    cout << ("a" < "a") << endl;
    cout << ("a" < "aa") << endl;
    cout << ("aa" < "aaa") << endl;
    cout << "--------------------------------" << endl;
    cout << ("ab" < "aaa") << endl;
    cout << ("ab" < "a") << endl;
    cout << ("ab" < "ac") << endl;

}

// || or   priority 9
// && and  priority 8
// ! not   priority 2

// cin >> cout << priority 5