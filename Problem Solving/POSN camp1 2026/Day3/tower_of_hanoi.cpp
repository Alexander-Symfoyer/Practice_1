#include <bits/stdc++.h>
using namespace std;

void hanoi(int n, int from, int to, int auxiliary) {

    if (n == 1) {
        cout << from << " " << to << '\n';
        return;
    }

    hanoi(n - 1, from, auxiliary, to);

    cout << from << " " << to << '\n';

    hanoi(n - 1, auxiliary, to, from);

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int total_moves = pow(2,n) - 1;
    cout << total_moves << '\n';

    hanoi(n, 1, 3, 2);

    return 0;
}