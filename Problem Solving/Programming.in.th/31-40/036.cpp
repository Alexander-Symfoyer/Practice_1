#include <iostream>
#include <cmath>
using namespace std;
int main() {

    int n; cin >> n;
    int k = n / 2;
    
    if (n % 2 == 0) {
        long long upper = 1;
        long long lower = 1;
        for (int i = 1; i <=  n; i++) {
            upper *= i;
        }
        for (int i = 1; i <= n / 2; i++) {
            lower *= i;
        }
        lower *= lower;

        cout << upper / lower;
    }

    else {
        long long upper = 1;
        long long lower = 1;
        for (int i = 1; i <= n; i++) {
            upper *= i;
        }
        for (int i = 1; i <= n / 2 + 1; i++) {
            lower *= i;
        }
        for (int i = 1; i <= n / 2; i++) {
            lower *= i;
        }

        cout << 2 * upper / lower;
    }
    

}