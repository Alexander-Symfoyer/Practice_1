#include <iostream>
#include <vector>
using namespace std;

int n;
vector<bool> used;
vector<bool> forbidden;
vector<int> sol;


void permutation(int len) {

    if (len == n) {                 //* Base case
        for (int i : sol) {
            cout << i << " ";
        }   cout << '\n';
        return;
    }   

    for (int i = 1; i <= n; i++) {

        if (used[i]) continue;
        if (len == 0 && forbidden[i]) continue;

        sol[len] = i;
        used[i] = true;

        permutation(len + 1);   //* Recursive

        used[i] = false;        //* Backtracking

    }

}


int main() {

    int m; 
    cin >> n;
    cin >> m;

    used.resize(n + 1, false);
    forbidden.resize(n + 1, false);
    sol.resize(n);

    for (int i = 0; i < m; i++) {
        int x; 
        cin >> x;
        forbidden[x] = true;
    }

    permutation(0);

}