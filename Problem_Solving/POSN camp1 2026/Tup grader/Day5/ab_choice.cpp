#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int a, b;
    string o;
    cin >> a >> b >> o;

    if (a < 0 || b > 100 || o.size() > 5 || a > 100) return 0; 

    if (o == "+") {
        cout << a + b;
    }
    else if (o == "-") {
        cout << a - b;
    }
    else if (o == "x" || o == "X") {
        cout << a * b;
    }
    else {
        cout << "Fail";
    }
}