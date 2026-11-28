#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);
    int n = s.size();
    long long ans = 0;
    int i = 0;
    int sign = 1;

    while (i < n && s[i] == ' ') {      //* Skip whitespace
        i++;
    }

    if (i < n && s[i] == '-') {         //* Change sign ('+', '-')
        sign = -1;
        i++;
    }
    else if (i < n && s[i] == '+') {
        i++;
    }

    while (i < n && isdigit(s[i])) {
        int digit = s[i] - '0';
        if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && digit > (sign == 1 ? 7 : 8)) {     //* Check overflow
            if (sign == 1) {              
                cout << INT_MAX;
            }
            else {
                cout <<  INT_MIN;
            }
        }
        ans = ans * 10 + digit;
        i++;
    }


    cout << ans * sign;

}