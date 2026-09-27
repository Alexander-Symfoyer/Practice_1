#include <iostream>
#include <string>
using namespace std;
int main() {

    string a = "1010";
    string b = "1011";

    int i = a.size() - 1;       //* Start from the rightmost digit
    int j = b.size() - 1;
    int carry = 0;              //* Carry from the previous addition
    string ans = "";

    while (i >= 0 || j >= 0 || carry) {

        int x = (i >= 0) ? a[i] - '0' : 0;      //* Get current digit from a, or 0 if a is finished
        int y = (j >= 0) ? b[j] - '0' : 0;

        int sum = x + y + carry;
        int digit = sum % 2;
        ans = char('0' + digit) + ans;          //* Add the digit to the front
                                                // sum = 0 : carry = 0, digit = 0
                                                // sum = 1 : carry = 0, digit = 1
        carry = sum / 2;                        // sum = 2 : carry = 1, digit = 0
                                                // sum = 3 : carry = 1, digit = 1

        i--;        //* Move both pointers to the left
        j--;

    }

    if (carry) {            //* If a carry remains
        ans = '1' + ans;
    }

    cout << ans;

}