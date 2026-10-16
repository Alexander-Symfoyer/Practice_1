#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int days, first, birth;
    cin >> days >> first >> birth;

    int lucky = 0;

    int column = (first + birth - 2) % 7;

    if (birth - 7 > 0) {
        lucky += birth - 7;
    }
    if (birth + 7 <= days) {
        lucky += birth + 7;
    }
    if (column > 0) {
        lucky += birth - 1;
    }
    if (column < 6 && birth + 1 <= days) {
        lucky += birth + 1;
    }

    cout << lucky;

}