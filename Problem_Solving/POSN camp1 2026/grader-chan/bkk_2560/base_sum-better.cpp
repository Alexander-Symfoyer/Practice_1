#include <bits/stdc++.h>
using namespace std;

int to_value(char c) {

    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    else {
        return c - 'A' + 10;
    }

}

int to_char(int x) {

    if (x <= 9) {
        return '0' + x;
    }
    else {
        return 'A' + x - 10;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int base;
    string a,b;
    cin >> base >> a >> b;

    int i = a.size() - 1;
    int j = b.size() - 1;
    int carry = 0;

    string soln;

    while (i >= 0 || j >= 0 || carry) {

        int x = 0;
        int y = 0;

        if (i >= 0) {
            x = to_value(a[i]);
        }
        if (j >= 0) {
            y = to_value(b[j]);
        }

        int sum = x + y + carry;
        soln += to_char(sum % base);

        carry = sum / base;
        i--;
        j--;

    }

    reverse(soln.begin(), soln.end());

    std::cout << soln;

}