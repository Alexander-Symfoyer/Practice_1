#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "abcabcabcabc";
    
    int n = s.size();
    for (int i = 1; i <= n / 2; i++) {
        if (n % i == 0) {
            string temp = s.substr(0, i);
            string t;
            for (int j = 1; j <= n / i; j++) {
                t += temp;
            }
            if (t == s) {
                cout << "True";
                return 0;
            }
            else continue;
        }
        else continue;
    }

    cout << "False";

}