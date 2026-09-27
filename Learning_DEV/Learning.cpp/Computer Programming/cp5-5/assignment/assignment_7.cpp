#include <bits/stdc++.h>
using namespace std;

int value = 100;

int main() {
    int value = 50;
    cout << value << '\n';
    {
        int value = 10;

        cout << value << '\n';
        cout << ::value << '\n';

    }
    return 0;
}