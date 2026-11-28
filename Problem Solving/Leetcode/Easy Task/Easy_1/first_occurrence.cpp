#include <iostream>
#include <string>
using namespace std;
int main() {

    string haystack = "dasbutsad";
    string needle = "sad";

    if (needle.size() > haystack.size()) {
        cout << -1;
    }

    for (int i = 0; i <= haystack.size() - needle.size(); i++) {

        bool found = true;

        for (int j = 0; j < needle.size(); j++) {

            if (haystack[j + i] != needle[j]) {
                found = false;
                break;
            }

        }

        if (found) {
            cout << i;
            return 0;
        }

    }

    cout << -1;

}