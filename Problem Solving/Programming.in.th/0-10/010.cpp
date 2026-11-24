#include <iostream>
using namespace std;
int main() {

    string str;
    cin >> str;
    int x = 1;
    for (char i : str) {
        if (i == 'C' && x == 1) {
            x += 2;
        } 
        else if (i == 'C' && x == 3) {
            x -= 2;
        }
        else if (i == 'A' && x == 1) {
            x += 1;
        }
        else if (i == 'A' && x == 2) {
            x -= 1;
        }
        else if (i == 'B' && x == 2) {
            x += 1;
        }
        else if (i == 'B' && x == 3) {
            x-= 1;
        }
    }

    cout << x;

}