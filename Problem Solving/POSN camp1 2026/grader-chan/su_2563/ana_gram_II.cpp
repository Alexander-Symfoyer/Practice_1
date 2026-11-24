#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string anagram_1, anagram_2;
    cin >> anagram_1 >> anagram_2;

    unordered_map<char, int> count_1;
    unordered_map<char, int> count_2;

    for (int i = 0; i < 8; i++) {
        count_1['A' + i] = 0;
        count_2['A' + i] = 0;
    }

    for (const char& c : anagram_1) {
        count_1[c]++;
    }
    for (const char& c : anagram_2) {
        count_2[c]++;
    }

    vector<int> diff;
    for (int i = 0; i < 8; i++) {
        diff.push_back(abs(count_1['A' + i] - count_2['A' + i]));
    }

    bool is_anagram = true;
    int freq = 0;
    for (const int& x : diff) {
        if (x != 0) freq++;
        if (freq == 4) {
            is_anagram = false;
            break;
        }
    }

    for (int i = 0; i < 8; i++) {
        cout << count_1['A' + i] << " ";
    }   cout << '\n';

    for (int i = 0; i < 8; i++) {
        cout << count_2['A' + i] << " ";
    }   cout << '\n';

    for (int i = 0; i < 8; i++) {
        cout << diff[i] << " ";
    }   cout << '\n';

    if (is_anagram) {
        cout << "anagram" << '\n';
    }
    else {
        cout << "no" << '\n';
    }

}