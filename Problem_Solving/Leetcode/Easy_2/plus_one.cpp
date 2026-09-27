#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> nums) {

    for (int x : nums) {
        cout << x << " ";
    }

}

int main() {

    vector<int> digits = {9,9,9};

    int n = digits.size() - 1;

    for (int i = n; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i]++;
            print(digits);
            return 0;
        }
        else {
            digits[i] = 0;

        }
    }

    digits.insert(digits.begin(), 1);
    print(digits);

}