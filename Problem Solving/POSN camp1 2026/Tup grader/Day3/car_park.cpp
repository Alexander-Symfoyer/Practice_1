#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int h1, h2, m1, m2, park_time;
    cin >> h1 >> m1;
    cin >> h2 >> m2;

    int t1 = m1 + (h1 * 60);
    int t2 = m2 + (h2 * 60);
              
    if (t2 >= t1) {
        park_time = abs(t2 - t1);
    }
    else {
        park_time = (1440 - t1) + t2;
    }
    int park_fee = 0;

    if (park_time <= 15) {
        park_fee = 0;
    }
    else {
        if (park_time <= 240) {
            park_fee = (park_time + 59) / 60 * 15;
        }
        else if (park_time > 240 && park_time <= 480) {
            park_fee = ((((park_time + 59) / 60) - 4) * 25) + 60;
        }
        else {
            park_fee = 200;
        }
    }

    cout << park_fee << '\n';

}