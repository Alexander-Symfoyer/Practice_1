#include <iostream>
#include <set>
using namespace std;
int main() {

    set<int> s;
    for (int i = 0; i < 10; i++) {
        int x;
        cin >> x;
        int output = x % 42;
        s.insert(output);
    }

    cout << s.size();

}