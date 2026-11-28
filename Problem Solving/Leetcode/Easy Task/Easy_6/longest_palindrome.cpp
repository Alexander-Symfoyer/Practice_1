#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abccccdd";
    int soln = 0;

    unordered_map<char, int> freq;

    for (char c : s) {
        freq[c]++;
    }

    for (auto [key, value] : freq) {

        if (value >= 2 && value % 2 == 0){
            soln += value;
        }
        else if (value >= 2 && value % 2 == 1) {
            soln += value - 1;
        }

    }

    for (auto [key, value] : freq) {
        if (value == 1 || (value % 2 == 1 && value >= 2)) {
            soln += 1;
            break;
        }
    }

}