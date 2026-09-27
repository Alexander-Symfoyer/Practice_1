#include <iostream>
#include <string>
using namespace std;
int main() {

    int x;
    cin >> x;

    if (x < 11) {
        cout << "False";
        return 0;
    }

    string s;
    s = to_string(x);
    int mid = s.size() / 2;

    for (int i = 0; i < mid; i++) {
        if (s[i] == s[s.size() - i - 1]) continue;
        else {
            cout << "False";
            return 0;
        }
        
    }

    cout << "True";


}