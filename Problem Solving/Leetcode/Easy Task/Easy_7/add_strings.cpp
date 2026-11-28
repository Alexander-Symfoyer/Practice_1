#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num1 = "198";
    string num2 = "99";
    string soln;

    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    while (i >= 0 || j >= 0 || carry) {

        int a = 0;
        int b = 0;

        if (i >= 0) {
            a = num1[i] - '0';
        }
        if (j >= 0) {
            b = num2[j] - '0';
        }

        int sum = a + b + carry;

        soln += to_string(sum % 10);
        carry = sum / 10;
        i--;
        j--;

    }

    reverse(soln.begin(), soln.end());

    cout << soln;

}