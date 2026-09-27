#include <bits/stdc++.h>
using namespace std;
int main() {

    int n;
    cin >> n;   //* Reads until white spaces (space tab newline)
    cin.ignore();

    string m;
    getline(cin, m);    //* Reads until newline (full line) (only use for string)

    string s = "case stylus camera keyboard";
    stringstream ss(s);
    string x;
    while (ss >> x) {
        cout << x << '\n';
    }   

}