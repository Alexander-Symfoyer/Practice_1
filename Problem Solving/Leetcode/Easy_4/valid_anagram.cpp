#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {

    string s = "anagram";
    string t = "nagaram";

    if (s.size() != t.size()) {
        cout << "False";
        return 0;
    }

    int count[26] = {};
    fill(count, count + 26, 0);



}