#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num;
    cin >> num;

    if (num == 0) {
        cout << "0";
        return 0;
    }

    unsigned int n = num;     //* unsigned int 0 → 4,294,967,295

    string ans;
    while (n != 0) {

        int digit = n & 0xF;
        char c;

        if (digit >= 10) {
            c = 'a' + (digit - 10);
        }

        else {
            c = '0' + digit;
        }

        ans += c;
        n >>= 4;

    }

    reverse(ans.begin(), ans.end());
    cout << ans;

}