#include <iostream>
#include <vector>


using namespace std;


void permutation(vector<int> &sol, vector<bool> &used, int len, int n) {    //* Generate all permutations

    if (len == n) {                         //* All posistion are filled

        for(int i = 0; i < n; i++) {        //* Print the current permutation
            cout << sol[i] << " ";
        }
        cout << '\n';
        return;

    }

    for (int i = 1; i <= n; i++) {           //* Try every number

        if (used[i]) continue;              //* Skip is this number already used

        sol[len] = i;                       //* Pick this number
        used[i] = true;

        permutation(sol, used, len + 1, n);     //* Fill the next position

        used[i] = false;                    //* Unpick this number

    }

}


int main() {

    int n = 3;                          //* number of elements

    vector<int> sol(n);
    vector<bool> used(n + 1, false);

    permutation(sol, used, 0, n);

}