#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    vector<char> v = {'a', 'e', 'i', 'o', 'u'};
    string s;
    getline(cin, s);
    string output;
    for (int i = 0; i < s.size(); i++) {

        if (find(v.begin(), v.end(), s[i]) == v.end()) {
            output += s[i];
        } else {
            output += s[i];
            i += 2;
        }

    }

    cout << output;

}