#include <iostream>
#include <string>
using namespace std;
int main() {

    string s1 = "123";
    int x = stoi(s1);
    cout << x + 1;

    string s2 = to_string(x + 1);
    cout << " " << s2 << " ";

    cout << (char)tolower('A') << " ";
    cout << (char)toupper('a') << " ";
    
    cout << '\n';

    cout << isdigit('5') << " ";
    cout << isalpha('A') << " ";
    cout << isalnum('c') << " ";
    cout << isspace(' ') << " ";

    

}