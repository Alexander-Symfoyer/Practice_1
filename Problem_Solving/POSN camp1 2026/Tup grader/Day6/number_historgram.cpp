#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    if (n < 1 || n > 40) return 0;
    unordered_map<char, int> count;

    for (int i = 0; i <= 9; i++) {
        count['0' + i] = 0;
    }

    for (int i = 0; i < n; i++) {
        string s;    
        cin >> s;
	if (stoi(s) < 0 || stoi(s) > 100000) return 0;
        for (int j = 0; j < s.size(); j++) {
            count[s[j]]++;
        }
    }

    for (int i = 0; i <= 9; i++) {
        cout << i << '|';
        for (int j = 0; j < count['0' + i]; j++) {
            cout << "*";
        }
        cout << '\n';
    }
}