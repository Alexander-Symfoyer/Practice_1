#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;


void print(vector<int> v) {
    cout << "Size of V is " << v.size() << " : ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> v = {9,3,4,1,10,2,5,6,7,8};
    sort(v.begin(), v.end() + 1);               //* sort(a, before b)
    print(v);                               
}