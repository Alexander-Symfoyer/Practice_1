#include <iostream>
#include <set>
using namespace std;
int main() {

    int n = 19;
    set<int> seen;

    while (n != 1) {

        if (seen.find(n) != seen.end()) {
            cout << "False";
            return 0;
        }
        seen.insert(n);

        int sum = 0;
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }

        n = sum;

    }

    cout << "True";

}