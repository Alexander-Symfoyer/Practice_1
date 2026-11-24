#include <bits/stdc++.h>
using namespace std;

int pun = 1;    //* Program wide-access

int main() {

    int score = 0;      // Init
    score = 10;         // Overwrite
    score += 5;         // Update

    int count;          // Uninitialization!
    count++;            // Undefined behaviour
    cout << count;      // Might print other number

    //* Camel case
    int currentScore = 0;

    //* Snake case
    int current_score = 0;

    //* Loop indices
    int i = 0;

    const double pi = 3.14;     //* Faster execution
    //pi += 1;  Error!

    int x = 0;      // Created
    x++;
    cout << x;      // x is destroyed here

    static int punn = 1;    //* Globally

    

}