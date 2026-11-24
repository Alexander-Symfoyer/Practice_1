#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

    int a,b,c;
    vector<int> v;
    cin >> a >> b >> c;
    v.push_back(a); v.push_back(b); v.push_back(c);
    string abc;
    cin >> abc;

    sort(v.begin(), v.end());
    
    for (int i = 0; i < 3; i++) {
        cout << v[abc[i] - 'A'] << " ";
    }
}