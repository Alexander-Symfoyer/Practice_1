#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    char c;
    
    cout << "Enter a string : "; cin >> s;
    
    cout << "Enter a char : "; cin >> c;  
    
    int pos = 0;  
    bool found = false;
    int i = 0;
    
    while (i < s.length()) {  
        if (s[i] == c) {
            found = true;
            pos = i;
            break;
        }
        cout << "Checked at " << i << endl;  
        i++;
    }
    
    if (found) {
        cout << "Found " << c << " at position " 
            << pos << endl;
    } else {
        cout << "Not found" << endl;
    }
    
    return 0;
}