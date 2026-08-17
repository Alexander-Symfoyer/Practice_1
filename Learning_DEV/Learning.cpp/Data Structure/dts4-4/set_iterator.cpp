#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
    
    set< pair<string, int> > s = {
        {"home", 7}, {"floor", 1}, {"desk", 3},
        {"home", 4}, {"cabinet", 1}
    };

    for (auto &x : s) {
        cout << x.first << " " << x.second << endl;
    }

    cout << "---- find ----" << endl;
    auto it = s.find( {"floor", 1} );
    cout << (*it).first << " " << (*it).second << endl;
    
    it--;
    it--;       //* iterator-- = previous

    cout << it->first << " " << it->second << endl;

    it++;       //* iterator++ = next
    cout << it->first << " " << it->second << endl;     //? " it-> " == " (*it)."

    

}

//! priority " . " > " * " 