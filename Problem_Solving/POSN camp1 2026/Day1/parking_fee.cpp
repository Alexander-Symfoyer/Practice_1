#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int minutes;
    cin >> minutes;
    minutes -= 60;
    if (minutes <= 0) {
        cout << 0;        
    }
    else {
        cout << (minutes + 59) / 60  * 20;
    }

    return 0;
}