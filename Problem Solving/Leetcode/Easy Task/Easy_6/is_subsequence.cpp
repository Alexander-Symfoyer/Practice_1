#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abc";
    string t = "ahbgdc";

    if (s.size() > t.size()) return 0;
    if (s.size() == t.size()) {
        if (s == t) return 1;
        else return 0;
    }


    int i = 0;
    int j = 0;

    while (i != s.size()) {

        if (j == t.size() - 1 && s[i] != t[j]) {
            return 0;
        } 
        if (j == t.size() - 1 && i != s.size() - 1) {
            return false;
        }

        if (s[i] == t[j]) {
            i++;
            j++;
        }
        else {
            j++;
        }
    }

    return 1;

}