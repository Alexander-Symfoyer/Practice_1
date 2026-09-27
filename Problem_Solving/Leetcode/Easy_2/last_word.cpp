#include <iostream>
#include <string>
using namespace std;
int main() {

    string s = "Hello World";
    int k = s.size() - 1;

    while (k >= 0 && s[k] == ' ') {
        k--;
    }

    int count = 0;
    while (k >= 0 && s[k] != ' ') {
        count += 1;
        k--;
    }

    cout << count;

}