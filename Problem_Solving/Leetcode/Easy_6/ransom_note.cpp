#include <bits/stdc++.h>
using namespace std;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string ransomNote = "aa";
    string magazine = "aab";

    int n = ransomNote.size();
    int m = magazine.size();

    if (n > m) return 0;
    if (ransomNote == magazine) return 1;

    unordered_map<char, int> freq;

    for (int i = 0; i < n; i++) {
        freq[ransomNote[i]]++;
    }

    for (int j = 0; j < m; j++) {
        if (freq.find(magazine[j]) != freq.end()){
            freq[magazine[j]]--;
        }
    }

    for (auto [key, value] : freq) {
        if (value != 0) {
            return 0;
        }
    }

    return 1;

}