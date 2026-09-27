#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "5F3Z-2e-9-w";
    int k = 4;
    string soln;
    string clean;

    for (char c : s) {
        if (c != '-') {
            clean.push_back(c);
        }
    }

    int count = 0;
    for (int i = clean.size() - 1; i >= 0; i--) {

        if (islower(clean[i])) {
            clean[i] = toupper(clean[i]);
        }
        soln += clean[i];

        count++;
        if (count == k && i != 0) {
            soln += '-';
            count = 0;
        }

    }

    reverse(soln.begin(), soln.end());

    cout << soln;

}