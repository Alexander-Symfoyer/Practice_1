#include <iostream>
#include <algorithm>
using namespace std;
int main() {                //! O(1)

    string s = "fyy";
    string t = "gbd";

    int mapping[128];                   //* ASCII has 128 characters
    int reverse[128];

    fill(mapping, mapping + 128, -1);       //* fill(first, last, value)
    fill(reverse, reverse + 128, -1);       //? fill(mapping[0], mapping[127], -1)

    for (int i = 0; i < s.size(); i++) {

        if (mapping[s[i]] != -1 && mapping[s[i]] != t[i]) {
            cout << "False";
            return 0;
        }
        
        if (reverse[t[i]] != -1 && reverse[t[i]] != s[i]) {
            cout << "False";
            return 0;
        }

        mapping[s[i]] = t[i];
        reverse[t[i]] = s[i];

    }

    cout << "True";

}