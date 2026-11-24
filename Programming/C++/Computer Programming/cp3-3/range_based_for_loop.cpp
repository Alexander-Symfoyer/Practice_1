#include <iostream>
using namespace std;

int main() {
    string s;
    cout << "Enter a string : "; cin >> s;
    for (auto c : s) {
        cout << c << endl;
    }

    bool unique = true;
    for (int p1 = 0; p1 < s.length(); p1++) {
        for (int p2 = p1+1; p2 < s.length(); p2++) {
            if (s[p1] == s[p2]) {
                unique = false;
                break;
            }
        }
    }
    if (unique) {
        cout << s << " is unique." << endl;
    } else {
        cout << s << " has repetitive char." << endl;
    }

    
}