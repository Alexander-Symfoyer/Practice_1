#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {            //* O(n)

    string s;
    cin >> s;
    bool upper = false;
    bool lower = false;
    for (char i : s) {
        if (isupper(i)) upper = true;
        if (islower(i)) lower = true;
    }

    if (upper && lower) cout << "Mix";
    else if (upper) cout << "All Capital Letter";
    else cout << "All Small Letter";

    return 0;

}