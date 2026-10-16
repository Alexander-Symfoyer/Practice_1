#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int last;
    cin >> last;

    int mom = (last + 145) % 7;
    cout << mom % 7 + 1;

}