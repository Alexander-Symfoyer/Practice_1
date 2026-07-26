#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {           
    
    set<int> s = {2,5,4,0,10,18,45,3,38,2,2,45,47};
    cout << "Size of S is " << s.size() << endl;

    s.insert(22);
    s.erase(5);

    cout << "Member of S : ";
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    cout << s.count(2) << endl;

    auto it1 = s.lower_bound(10);       //! lower/upper_bound must be in order
    cout << *it1 << endl;

    auto it2 = s.upper_bound(10);
    cout << *it2 << endl;

}

//? set slow insert 
//? fast lookup and erase
//? insert ++ -- find take log(n)