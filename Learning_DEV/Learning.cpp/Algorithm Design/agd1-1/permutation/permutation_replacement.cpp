#include <iostream>
#include <vector>

using namespace std;

void perm_replacement(
    int n,
    vector<int>& sol,
    int len,
    vector<bool>& used,
    int k
) {
    if (len < k) {

        for (int i = 1; i <= n; i++) {

            sol[len] = i;
            perm_replacement(n, sol, len + 1, used, k);

            }

    } else {

        for (auto &x : sol)
            cout << x;

        cout << endl;
    }
}

int main() {

    int n = 4;                  //* Total elements (1 2 3 4)
    int k = 2;                  //* elements to arrange

    vector<int> sol(k);
    vector<bool> used(n + 1, false);

    perm_replacement(n, sol, 0, used, k);
}