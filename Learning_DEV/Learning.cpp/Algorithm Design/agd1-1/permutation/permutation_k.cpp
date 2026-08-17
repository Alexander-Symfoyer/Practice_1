#include <iostream>
#include <vector>

using namespace std;

void perm_kn(
    int n,
    vector<int>& sol,
    int len,
    vector<bool>& used,
    int k
) {
    if (len < k) {

        for (int i = 1; i <= n; i++) {

            if (used[i] == false) {

                used[i] = true;
                sol[len] = i;

                perm_kn(n, sol, len + 1, used, k);

                used[i] = false;
            }
        }

    } else {

        for (auto &x : sol)
            cout << x;

        cout << endl;
    }
}

int main() {

    int n = 4;
    int k = 3;

    vector<int> sol(k);
    vector<bool> used(n + 1, false);

    perm_kn(n, sol, 0, used, k);
}