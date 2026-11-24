#include <bits/stdc++.h>
using namespace std;

void combi(int n, string current) {
    
    if (current.size() == n) {
        cout << current << '\n';
        return;
    }
    else {
        current += "0";
        combi(n, current);

        current.pop_back();
        current += "1";
        combi(n, current);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string current = "";
    combi(n, current);

}