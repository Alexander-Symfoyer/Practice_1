#include <iostream>
using namespace std;           
int main() {

    int n; cin >> n;
    int k = n / 2;
    long long ans = 1;
    for (int i = 1; i <= k; i++) {
        ans = ans * (n - i + 1) / i;
    }

    if (n % 2 == 1) ans *= 2;
    cout << ans;
    return 0;

}