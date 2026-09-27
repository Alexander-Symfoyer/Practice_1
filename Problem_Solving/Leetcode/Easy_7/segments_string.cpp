#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = " h h h h h ";
    int soln = 0;

    stringstream ss(s);
    string words;
    while (ss >> words) {
        soln++;
    }

    cout << soln;

}