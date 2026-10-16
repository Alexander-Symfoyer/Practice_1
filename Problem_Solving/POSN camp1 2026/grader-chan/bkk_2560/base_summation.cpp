#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int base;
    string num1, num2;
    cin >> base >> num1 >> num2;

    string output = "";
    

    unordered_map<char, int> value = {
        {'0', 0},
        {'1', 1}, {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
        {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9}, {'A', 10},
        {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14}, {'F', 15}
    };

    if (num1.size() < num2.size()) {
        string temp = num1;
        num1 = num2;
        num2 = temp;
    }
    
    int i = num1.size() - 1;
    int j = num2.size() - 1;
    int carry = 0;

    for (int x = 0; x < num2.size(); x++) {
        int digits = value[num1[i]] + value[num2[j]] + carry;
        int digit = digits % base;

        if (digit < 10) {
            output += to_string(digit);
        }
        else {
            if (digits < base) {
                output += char(((digit) % 10) + 'A');
            }
            else {
                output += char(((digit % base) % 10) + 'A');
            }
        }

        carry = digits / base;

        i--;
        j--;
    }

    for (int x = 0; x < num1.size() - num2.size(); x++) {
        int digits = value[num1[i]] + carry;
        int digit = digits % base;

        if (digit < 10) {
            output += to_string(digit);
        }
        else {
            if (digits < base) {
                output += char(((digit % 10)) + 'A');
            }
            else {
                output += char(((digit % base) % 10) + 'A');
            }
        }

        carry = digits / base;
        i--;
    }

    if (carry != 0) {
        output += to_string(carry);
    }

    reverse(output.begin(), output.end());

    std::cout << output;

}