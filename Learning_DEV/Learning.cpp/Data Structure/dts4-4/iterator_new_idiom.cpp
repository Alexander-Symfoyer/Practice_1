#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    vector<string> v1 = {"apple", "banana", "orange"};

    //range-based for loop
    for (string x : v1) {
        cout << x << " ";
    }
    cout << endl;

    for (auto &x : v1) {
        x.replace(0, 2, "ma");      //* x.replace(a,b,c)
    }                               //* replace from a to before b with c
    for (auto &x : v1) {
        cout << x << " ";           // & = Reference
    }
    cout << endl;

}