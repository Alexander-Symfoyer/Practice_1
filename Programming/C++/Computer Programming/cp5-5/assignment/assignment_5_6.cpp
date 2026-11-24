#include <bits/stdc++.h>
using namespace std;

int global = 10;

void scope_demo() {

    int global = 20;
    cout << global;
    cout << " " << ::global << '\n';       //* Global scope

}

void call_function() {

    static int count;;      //* Create once and always remember values
    count++;
    cout << count << '\n';

}

int main() {

    scope_demo();

    for (int i = 0; i < 5; i++) {
        call_function();
    }

}