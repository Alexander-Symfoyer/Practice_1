#include <iostream>                 //* Greatest common divider = gcd
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    int ans = 1;
    for (int i = 2; i < min(a,b); i++) {
        if (a % i == 0 && b % i == 0) {
            ans = i;
        }
    }
    return ans;
}


int main() {
    
    cout << GCD(72, 96) << '\n';
    cout << GCD(4123, 78324) << '\n';

}