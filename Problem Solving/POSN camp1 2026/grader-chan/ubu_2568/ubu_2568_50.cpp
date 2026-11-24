#include <iostream>
#include <vector>
using namespace std;
int main() {

    vector<int> num;        //* Stores the big integer one digit at a time
    num.push_back(1);

    for (int i = 2; i <= 100; i++) {        //* Build 100!

        int carry = 0;
        for (int j = 0; j < num.size(); j++) {
            int x = num[j] * i + carry;
            num[j] = x % 10;                //* Keep only current digit
            carry = x / 10;                 //* Pass the remaining value to the next digit
        }

        while (carry > 0) {
            num.push_back(carry % 10);
            carry /= 10;
        }

    }

    for (int i = num.size() - 1; i >= 0; i--) {
        cout << num[i];
    }

}