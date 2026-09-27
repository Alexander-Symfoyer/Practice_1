#include <iostream>
#include <unordered_map>
using namespace std;
int main() {                    //! O(1)

    unordered_map<int, int> mp;     //* (key_type, value_type)
    mp[10] = 50;
    mp[20] = 100;
    cout << mp[10] << '\n';

    mp[10] = 55;
    if (mp.find(10) != mp.end()) {      //* find(key)
        cout << "Found" << '\n';
    }

    mp.insert({30,155});
    mp.erase(20);
    cout << mp.size() << '\n';

}


