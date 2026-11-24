#include <iostream>
#include <vector>


using namespace std;


void combi(vector<int> &sol, int len, int n) {          //* Generate all combination

    if (len < n) {                          //* Still have items to decide

        sol[len] = 0;                       //* Don't pick this item
        combi(sol, len + 1, n);            
        sol[len] = 1;
        combi(sol, len + 1, n);             //* Pick this item

    } else {

        for (int i = 0; i < n; i++) {       //* Print the current combination
            if (sol[i] == 1) {              //* Print selected items
                cout << i + 1 << "";
            }
        }
        cout << "}" << '\n';                //* Move to next combination
    }

}


int main() {

    vector<int> sol(3);         //* Stores 0/1 for each item
    combi(sol, 0, 3);           //* Start for the first item

}