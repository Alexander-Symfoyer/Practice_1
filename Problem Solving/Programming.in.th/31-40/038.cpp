#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int n; cin >> n;
    vector<string> s;

    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        if (find(s.begin(), s.end() , x) == s.end()) {
            s.push_back(x); 
        }
    }

    sort(s.begin(), s.end());

    for (string x : s) {
        cout << x << '\n';
    }

}