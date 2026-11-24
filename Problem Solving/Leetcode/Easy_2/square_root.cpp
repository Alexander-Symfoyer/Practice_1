#include <iostream>
using namespace std;
int main() {

    int x = 101;
    int left = 1;
    int right = x;

    if (x == 0) cout << 0;

    while (left <= right) {

        int mid = left + (right - left) / 2;

        if (mid == x / mid && x % mid == 0) {
            cout << mid;
            return 0;
        }

        else if (mid <= x / mid) {
            left = mid + 1;
        }

        else {
            right = mid - 1;
        }

    }

    cout << right;              //* right * right <= x
                                //* left * left > x

}