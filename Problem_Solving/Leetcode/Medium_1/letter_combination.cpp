#include <bits/stdc++.h>
using namespace std;

string digits = "249";
vector<string> mapping = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
vector<string> ans;

void backtrack(int index, string current) {

    if (index == digits.size()) {
        ans.push_back(current);
        return;
    }

    string letters = mapping[digits[index] - '0'];

    for (const char& c : letters) {

        current.push_back(c);
        backtrack(index + 1, current);
        current.pop_back();

    }

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string current = "";
    int index = 0;

    backtrack(index, current);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }   cout << '\n';

}