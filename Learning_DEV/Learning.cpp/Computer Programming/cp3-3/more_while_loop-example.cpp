#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cout << "Enter a string : "; getline(cin,a);
    cout << a << endl;

    int n;
    cout << "Enter a number : "; cin >> n;
    int divisor = 2;
    while (divisor < n) {
        if (n % divisor == 0) {
            cout << "Not prime" << endl;
            break;
        }
        divisor++;
    }
    if (divisor == n) {
        cout << "Is prime" << endl;
    }

    string s,s2;
    cout << "Enter a string : "; cin >> s;
    int i = 0;
    while (i < s.length()) {
        s2 = s2 + s[s.length() - i - 1];
        i++;
    }
    cout << s2 << endl;

    while (i < s.length() / 2) {
        swap(s[i],s[s.length() - i - 1]);
        i++;
    }
    cout << s << endl;
}