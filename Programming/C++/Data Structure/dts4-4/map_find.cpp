#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {

    map<int, string> m;
    m[1] = "window";
    m[2] = "linux";
    cout << m[1] << endl;

    int k = 2;
    map<int, string>::iterator it;
    if ((it = m.find(k)) != m.end()) {
        cout << "Key " << it->first << " is mapped to " << it->second << endl;
    } else {
        cout << "Key " << k << " is not exists in m" << endl;
    }

    // this is not the correct ways
    if (m[k] != "") {           //! Ex m[5] will create new map
        cout << "Exists" << endl;
    } else {
        cout << "Does not exists" << endl;
    }

}

//* Set and Map key type must be comparable
//* Type that we can use directly 
//* int bool(0,1) float string double char and most of other numerical data type
//* pair also can 