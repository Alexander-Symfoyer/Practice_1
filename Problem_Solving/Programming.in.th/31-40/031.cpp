#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {

    int w, l, h;
    cin >> w >> l >> h;
    int count = 0;

    while (!(w == 1 && l == 1 && h == 1)) {

        int target = max({w,l,h});
        if (target == w) {
            w /= 2;
            count += 1;
        }
        else if (target == l) {
            l /= 2;
            count += 1;
        }
        else {
            h /= 2;
            count +=1;
        }

    }

    cout << count;

}