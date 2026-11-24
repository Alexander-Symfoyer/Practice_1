#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {

    string a,b;
    char op;
    cin >> a; cin >> op; cin >> b;

    if (op == '*') {
        string output = "1";
        output += string((a.size() - 1) + (b.size() - 1), '0');
        cout << output;
    }
    else if (op == '+') {
        
        string s;
        if (a.size() > b.size()) {
            s = a;
            s[s.size() - b.size()] = '1';
        }
        else if (a.size() < b.size()) {
            s = b;
            s[s.size() - a.size()] = '1';
        }
        else {
            s = "2" + string((a.size() - 1), '0');
        }

        cout << s;

    }

}