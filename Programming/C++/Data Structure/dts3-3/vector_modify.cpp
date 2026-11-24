#include <iostream>
#include <vector>
using namespace std;


void print(vector<int> v) {
    cout << "Size of V is " << v.size() << " : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    
    vector<int> v(3,10);
    print(v);

    v.insert(v.begin(), 9);         // x.begin() = iterator
    print(v);  
    
    v.insert(v.begin() + 2, 11);    // insert(position, value)
    print(v);                       

    v.insert(v.end(), 12);
    print(v);

    v.erase(v.begin());
    print(v);

    v.erase(v.begin() + 2);         // ! Both insert and erase position must valid
    v.erase(v.begin() + 2);
    print(v);

    v.pop_back();
    print(v);

}