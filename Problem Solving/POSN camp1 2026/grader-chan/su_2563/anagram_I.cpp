#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string anagram;
    cin >> anagram;

    unordered_map<char, int> count;

    for (int i = 0; i < 8; i++) {
        count['A' + i] = 0;
    }

    for (const char& c : anagram) {
        count[c]++;
    }
    
    for (int i = 0; i < 8; i++) {
        cout << count['A' + i] << " ";
    }   cout << '\n';

}