#include <bits/stdc++.h>
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    scanf("%d", &n);

    if (n <= 0) {
        cout << "False";
        return 0;
    }

    while (n % 3 == 0) { 
        n /= 3;
    }

    if (n != 1) cout << "False";
    else cout << "True";
    
}