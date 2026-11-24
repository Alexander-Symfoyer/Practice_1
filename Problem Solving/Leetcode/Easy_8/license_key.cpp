#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "5F3Z-2e-9-w";
    int k = 4;
    string soln;

    for (char c : s) {
        if (c != '-') {
            soln.push_back(c);
        }
    }

    int count = k;
    for (int i = soln.size() - 1; i >= 0; i--) {
        if (islower(soln[i])) {
            soln[i] = toupper(soln[i]);
        }
        if (count != 1) {
            count--;
            continue;
        }
        else {
            if (i != 0) {
                soln.insert(i, 1, '-');
            }
            count = k;
        }
    }   

    cout << soln;

}