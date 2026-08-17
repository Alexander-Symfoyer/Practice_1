#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    
    //map between "Key Type" string and "Mapped Type" int
    map<string, int> m;     // map is similar to set and pair 
    m["mouse"] = 10;
    m["keyboard"] = -5;
    m["monitor"] = 25;
    cout << "Size of M is " << m.size() << endl;

    for (auto it = m.begin(); it != m.end(); it++) {
        cout << it->first << " is mapped to " << it->second << endl;
    }

    // this will create mapping "speakers" to 0 first and then increase mapped type (0)
    m["speakers"]++;

    cout << "Now size is " << m.size() << endl;
    for (auto &x : m) {
        cout << x.first << " is mapped to " << x.second << endl;
    }

}