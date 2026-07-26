#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20};

    auto it = v.end() - 1;      //v.end() point after the last;
    
    // we resize v1, now it is invalidated
    v.resize(10);
    
    // this might not crash
    // but it actually points to somewhere not in v
    cout << *it << endl;

    // this will crash the program
    v.insert(it,99);
    for (auto &x : v) {
        cout << x << " ";
    }
    cout << endl;
}