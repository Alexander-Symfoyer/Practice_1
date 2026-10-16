#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < i; j++) {
            cout << " ";
        }

        cout << char('A' + (n - i - 1));

        for (int j = 0; j < (n - i - 2) * 2 + 1; j++) {
            cout << " ";
        }

        cout << char('A' + (n - i - 1));

        for (int j = 0; j < 1 + (i * 2); j++) {
            cout << " ";
        }

        cout << '*';

        for (int j = 0; j < (n - i - 2) * 2 + 1; j++) {
            cout << " ";
        }

        cout << '*';

        cout << '\n';
    }

    for (int i = 0; i < n - 1; i++) {
        cout << " ";
    }   cout << 'A';

    for (int i = 0; i < (n - 1) * 2 + 1; i++) {
        cout << " ";
    }   cout << '*' << '\n';


    for (int i = 0; i < n - 1; i++) {
        for (int j = n - 1; j > i + 1; j--) {
            cout << " ";
        }

        cout << char('A' + (i + 1));

        for (int k = 0; k < 1 + (2 * i); k++) {
            cout << " ";
        }

        cout << char('A' + (i + 1));

        for (int j = 0; j < ((n - 2) * 2 + 1) - (i * 2); j++) {
            cout << " ";
        }

        cout << '*';

        for (int j = 0; j < 1 + (i * 2); j++) {
            cout << " ";
        }

        cout << '*';

        cout << '\n';
    }

}