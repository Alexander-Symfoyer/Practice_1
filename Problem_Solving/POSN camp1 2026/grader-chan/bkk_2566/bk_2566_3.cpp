#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string digit;
    cin >> digit;

    unordered_map<char,vector<vector<char>>> dice = {
        {'1', {{' ',' ',' '}, {' ','*',' '}, {' ',' ',' '}}}, 
        {'2', {{' ','*',' '}, {' ',' ',' '}, {' ','*',' '}}}, 
        {'3', {{'*',' ',' '}, {' ','*',' '}, {' ',' ','*'}}}, 
        {'4', {{'*',' ','*'}, {' ',' ',' '}, {'*',' ','*'}}}, 
        {'5', {{'*',' ','*'}, {' ','*',' '}, {'*',' ','*'}}}, 
        {'6', {{'*',' ','*'}, {'*',' ','*'}, {'*',' ','*'}}}
    };

    string line1, line2, line3;

    for (char c : digit) {
        if (dice.find(c) == dice.end()) {
            line1 += "   ";
            line2 += "   ";
            line3 += "___";
            continue;
        }
        for (int i = 0; i < 3; i++) {
            line1 += dice[c][0][i];
        }
        for (int i = 0; i < 3; i++) {
            line2 += dice[c][1][i];
        }
        for (int i = 0; i < 3; i++) {
            line3 += dice[c][2][i];
        }
        line1 += ' ';
        line2 += ' ';
        line3 += ' ';
    }

    cout << line1 << '\n';
    cout << line2 << '\n';
    cout << line3 << '\n';

}