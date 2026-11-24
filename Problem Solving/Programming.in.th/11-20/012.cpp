#include <iostream>
using namespace std;
int main() {
    
    string str;
    cin >> str;
    int n = str.size();

    for (int i = 0; i < n; i++) {
        cout << (i % 3 == 2 ? "..*." : "..#.");
    }   cout << ".\n";

    for (int i = 0; i < n; i++) {
        cout << (i % 3 == 2 ? ".*.*" : ".#.#");
    }   cout << ".\n";
    
    for (int i = 0; i < n; i++) {
        if (i != 0 && i % 3 != 1) cout << "*." << str[i] << ".";
        else cout << "#." << str[i] << ".";
    }   cout << (n % 3 == 0 ? "*" : "#") << '\n'; 

    for (int i = 0; i < n; i++) {
        cout << (i % 3 == 2 ? ".*.*" : ".#.#");
    }   cout << ".\n";
    
    for (int i = 0; i < n; i++) {
        cout << (i % 3 == 2 ? "..*." : "..#.");
    }   cout << ".\n";

}