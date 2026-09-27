#include <bits/stdc++.h>
using namespace std;
int main() {

    string s = "competative programming";
    int freq[26] = {0};

    for (int i = 0; i < s.size(); i++) {
        if (s[i] != ' ') {
            freq[s[i] - 'a']++;
        }
    }

    for (int i = 0; i < size(freq); i++) {
        if (freq[i] > 1) {                  //? Letters that appear more than once
            cout << char(i + 'a') << " ";
        }
    }   cout << '\n';

}