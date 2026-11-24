#include <iostream>
using namespace std;

int main() {
    string s; int a;
    cout << "Enter a string : "; cin >> s;
    cout << "Enter a position that contain a letter 'z' : "; cin >> a;
    if (a >= 0 && a < s.length() && s[a] == 'z')
        cout << "correct!" << endl;

    int b;
    cout << "Enter an integer : "; cin >> b;
    int abs = b >= 0 ? b: -b;
    cout << "The absolute value is " << abs << endl;
}