#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    string soln = "";
    cin >> s;
    
    map<char, int> freq;
    for (int i = 0; i < 26; i++) {
        freq[('A' + i)] = 0;
    }
    for (const char& c : s) {
        freq[c]++;
    }

    int count = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[('A' + i)] % 2 == 1) {
            count++;
        }
        if (count > 1) {
            cout << "NO SOLUTION" << '\n';
            return 0;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq['A' + i] % 2 == 0) {
            for (int j = 0; j < freq[('A' + i)] / 2; j++) {
                soln += ('A' + i);
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (freq[('A' + i)] % 2 == 1) {
            for (int j = 0; j < freq[('A' + i)]; j++) {
                soln += ('A' + i);
            }
        }
    }

    for (int i = 25; i >= 0; i--) {
        if (freq['A' + i] % 2 == 0) {
            for (int j = 0; j < freq[('A' + i)] / 2; j++) {
                soln += ('A' + i);
            }
        }
    }

    cout << soln;

}