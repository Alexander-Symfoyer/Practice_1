#include <bits/stdc++.h>
using namespace std;
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char grade;
    scanf("%c", grade);

    switch(grade) {
        case 'A':
        cout << "Excellent";
        break;

        case 'B':
        cout << "Good";
        break;

        default :
        cout << "Keep trying";
    }

    //* Ternary Operator
    //* condition ? if_true : if_false

    int a = 5; int b = 7;
    int max_val = (a > b) ? a : b;
    cout << '\n';
    cout << max_val;

}