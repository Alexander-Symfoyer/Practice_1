#include <bits/stdc++.h>
using namespace std;

void execute(string& s) {

    int write = 0;
    for (const char& c : s) {
        if (isspace(c)) {
            continue;
        }
        s[write++] = toupper(c);
    }

    s.resize(write);
    reverse(s.begin(), s.end());

}

int main() {

    string s = "hello world";
    execute(s);
    cout << s;

}