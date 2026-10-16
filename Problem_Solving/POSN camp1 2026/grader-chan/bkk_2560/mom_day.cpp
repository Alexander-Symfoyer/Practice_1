#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int month, day;
    cin >> month >> day;

    vector<int> days = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    int offset = 0;

    if (month < 8) {
        for (int m = month; m < 8; m++) {
            offset += days[m - 1];
        }
        offset += 11;
    }   
    else if (month == 8) {
        offset = 11;
    }
    else {
        for (int m = 8; m < month; m++) {
            offset -= days[m - 1];
        }
        offset += 11;
    }

    int mom = ((day + offset - 1) % 7 + 7) % 7 + 1;
    cout << mom;

}