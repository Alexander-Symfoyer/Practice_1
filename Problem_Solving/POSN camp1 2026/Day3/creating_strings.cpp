#include <bits/stdc++.h>
using namespace std;

void create(string s, string current, vector<bool> used) {

    if (current.size() == s.size()) {
        cout << current << '\n';
    }

    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    vector<bool> used(s.size(), 0);
    create(s, "", used);

    return 0;
}