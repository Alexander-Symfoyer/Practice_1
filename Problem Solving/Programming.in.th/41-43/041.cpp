#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main() {

    int n;
    cin >> n;

    double ans;

    if (n == 1) ans = 2.0;

    else if (n == 2) ans = 2.0;

    else if (n == 3) {
        ans = 2.0 + sqrt(3.0); 
    }

    else if (n % 2 == 0) {
        ans = n;
    }

    else {
        ans = n - 3 + 2.0 * sqrt(3.0);
    }

    cout << fixed << setprecision(6) << ans;

}