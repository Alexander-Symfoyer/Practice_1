#include <iostream>
#include <cmath>
using namespace std;
int main() {

    string columnTitle = "ZY";
    int target;
    int ans = 0;
    for (char c : columnTitle) {

        target = (c - 'A') + 1;
        ans = ans * 26 + target;            //* Number base 26;

    }
    cout << ans;

}