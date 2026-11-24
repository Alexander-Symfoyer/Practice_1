#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string words;
    cin >> words;

    int freq[26] = {};

    for (int i = 0; i < words.size(); i++) {
        freq[words[i] - 'A']++;
    }

    for (int i = 0; i < 26; i++) {

        if (freq[i] == 1) {
            cout << char(i + 'A');
            return 0;
        }
        else {
            continue;
        }
    }

    cout << "";

}