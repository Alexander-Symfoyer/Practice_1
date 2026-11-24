#include <iostream>
#include <string>
using namespace std;
int main() {

    int n;
    cin >> n;
    
    while(n--) {

        string x;
        cin >> x;

        if (x.back() % 2 == 1) {
            cout << "T\n";
        }

        else if (x == "2") {
            cout << "T\n";
        }

        else {
            cout << "F\n";
        }

    }

}