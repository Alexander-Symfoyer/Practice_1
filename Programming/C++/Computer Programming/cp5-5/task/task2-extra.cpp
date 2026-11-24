#include <bits/stdc++.h>
using namespace std;

string execute(const string& s) {

    string output;
    output.reserve(s.size());

    for (auto it = s.rbegin(); it != s.rend(); ++it) {  
        if (isspace(*it)) {                 //* rend() before begin()
            continue;                       //* rbegin() after end()
        }
        output.push_back(toupper(*it));
    }

    return output;

}

int main() {

    string s = "banana";
    cout << execute(s);
    

}