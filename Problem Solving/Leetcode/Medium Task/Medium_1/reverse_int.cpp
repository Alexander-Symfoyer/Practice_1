#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x;
    scanf("%d", &x);

    int ans = 0;
    while (x != 0) {
        
        int digit = x % 10;
        x /= 10;

        if (ans > INT_MAX / 10 || ans == INT_MAX / 10 && digit > 7) {
            return 0;       //! Check positive overflow (2,147,483,647)
        }

        if (ans < INT_MIN / 10 || ans == INT_MIN / 10 && digit  < -8) {
            return 0;       //! Check negative overflow (-2,147,483,648)
        }

        ans = ans * 10 + digit;

    }

    cout << ans;

}