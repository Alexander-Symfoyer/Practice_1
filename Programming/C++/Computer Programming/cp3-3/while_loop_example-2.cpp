#include <iostream>
using namespace std;

int main() {
    
    string s,s2;
    char c;
    cout << "Enter a string : "; cin >> s;
    cout << "Enter a char : "; cin >> s2;
    c = s2[0];
    int i = 0, pos;
    bool found = false;
    while (i < s.length()) {
        if (s[i] == c) {
            found = true;
            pos = i;
        }
        i++;
    }

    if (found) {
        cout << "Found " << c << " at position " 
            << pos << endl;
    } else {
        cout << "Not found" << endl;
    }
}